#include <Camera.h>
#include "ESP8266ATLib.h"
#include <SPI.h>

// #define SDDEBUG
// #define SAP_MODE
#define BAUDRATE 115200
#define BUFSIZE 2048

#ifdef SDDEBUG
#include <SDHCI.h>
SDClass theSD;
#endif

#ifdef SAP_MODE
#define SSID "SprESP8266AP"
#define PASS "123123123"
#else
//#define SSID "HR01a-62F4B1"
//#define PASS "7c2ff42ce0"
//#define SSID "tsukarm_underground_lab_2.4g"
//#define PASS "underground404"
#define SSID "Chintaka-Lab"
#define PASS "65596357"
#endif

void setup() {
  Serial.begin(115200);
  theCamera.begin();
  Serial.println("Set Auto white balance parameter");
  theCamera.setAutoWhiteBalanceMode(CAM_WHITE_BALANCE_FLUORESCENT);
  theCamera.setStillPictureImageFormat(320, 240, CAM_IMAGE_PIX_FMT_JPG);

  esp8266at.begin(BAUDRATE);
#ifdef SAP_MODE
  esp8266at.espStartAP(SSID, PASS);
#else
  esp8266at.espConnectAP(SSID, PASS);
#endif
  digitalWrite(LED0, HIGH);
  esp8266at.setupTcpServer("80");
  digitalWrite(LED1, HIGH);

  Serial.println();
  Serial.println("---------------------------------------------");
  Serial.println("Try to access the address below.");
  Serial.println("http://" + esp8266at.getLocalIP() + "/cam.jpg");
  Serial.println("You can see a captured picture on the page");
  Serial.println("---------------------------------------------");
  Serial.println();

  // SPI setup
  SPI5.begin();
  SPI5.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE3));
  Serial.println("SPI Setup Complete");

  // esp8266at.setWaitTime(100);
}

bool isTransmitting = false;  // Prevent concurrent transmissions

// SPI functions
static inline int spigetb() {
  return SPI5.transfer(0) & 0xff;
}

static int spigeth() {
  return (spigetb() << 8) | spigetb();
}

static int spigetw() {
  return (spigetb() << 24) | (spigetb() << 16) | (spigetb() << 8) | spigetb();
}

static void spiskip(int len) {
  while (len > 0) {
    spigetb();
    len--;
  }
}

static void spicommandinner(int cmd, int val) {
  SPI5.transfer(0xeb);
  SPI5.transfer(cmd);
  SPI5.transfer(1);
  SPI5.transfer(val);
  SPI5.transfer(0xed);
}

static void spicommand(int cmd, int val) {
  spicommandinner(cmd, val);
  spiskip(256 - 5);
}

void loop() {
  // --- SPI Reading Section (Does NOT interfere with Transmission) ---
  spiskip(256);
  //delay(300);
  spicommand(0, 0xff);  // sync mode
  //delay(300);
  spiskip(256);
  spiskip(spigetb());  // sync
  spicommand(0, 0);    // normal mode
  //delay(300);

  spicommand(0x10, 0);  // 256 frames/s
  //delay(300);
  spiskip(256);

  static int oldseq = -1;
  int magic0 = spigetb();
  int seq0 = spigetb();
  spiskip(2); /* ver h/l */
  int range = spigetw();

  spiskip(256 - 9);
  int seq1 = spigetb();

  if (magic0 == 0xe9 && seq0 == seq1 && ((oldseq - seq0) & 0x80) == 0) {
    oldseq = seq0;
    int dis = range / (0x400000 / 1000);

    Serial.print(" >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Distance: ");
    Serial.print(dis);
    Serial.println(" mm");
  }

  // --- Image Transmission Section ---
  if (isTransmitting) {
    Serial.println("Ignoring new request: Transmission in progress.");
    return;  // Ignore new requests while transmitting an image
  }

  digitalWrite(LED2, LOW);
  String linkID = "";
  String s = esp8266at.espListenToClient(&linkID);

  if (!(s.startsWith("+IPD") && s.indexOf("HTTP/1"))) return;
  if (s.indexOf("GET") < 0) return;  // Only accept GET requests

  Serial.println(s);

  if (s.indexOf("cam.jpg") != -1) {
    isTransmitting = true;  // Lock transmission
    digitalWrite(LED2, HIGH);

    int retryCount = 0;
    bool success = false;

    while (retryCount < 3 && !success) {  // Retry up to 3 times if needed
      Serial.println("Attempt #" + String(retryCount + 1) + ": Taking a picture");
      CamImage img = theCamera.takePicture();
      int len = img.getImgSize();
      uint8_t* imgbuf = img.getImgBuff();

      if (len == 0 || imgbuf == NULL) {
        Serial.println("Error: Failed to capture image, retrying...");
        retryCount++;
        delay(100);
        continue;
      }

      Serial.println("Image Size: " + String(len));

      // ---------------- Add ToF Distance to HTTP Headers ----------------
      int dis = range / (0x400000 / 10000);  // Convert range to mm

      dis = len/100;
      String msg = "HTTP/1.1 200 OK\r\n";
      msg += "Content-Type: image/jpeg\r\n";
      msg += "Content-Length: " + String(len) + "\r\n";
      msg += "X-ToF-Distance: " + String(dis) + "\r\n";  // Custom header
      msg += "\r\n";
      Serial.print(msg);
      // ------------------------------------------------------------------

      if (!esp8266at.sendMessageToClient(linkID, msg)) {
        Serial.println("Error: Failed to send HTTP header");
        esp8266at.closeClientConnection(linkID);
        retryCount++;
        delay(100);
        continue;
      }

      // Send Image Data
      bool transmissionSuccess = true;
      for (; len > 0; imgbuf += BUFSIZE, len -= BUFSIZE) {
        uint16_t sendDataSize = min(len, BUFSIZE);
        Serial.println("Sending data chunk of size: " + String(sendDataSize));

        if (!esp8266at.sendBinaryToClient(linkID, imgbuf, sendDataSize)) {
          Serial.println("Transmission Error: Data send failed");
          transmissionSuccess = false;
          break;
        }
      }

      if (transmissionSuccess) {
        Serial.println("Image successfully transmitted.");
        success = true;
      } else {
        Serial.println("Retrying image transmission...");
        esp8266at.closeClientConnection(linkID);  // Ensure connection is reset
        retryCount++;
        delay(200);
      }
    }

    delay(200);  // Prevent resource overload between transmissions

    if (!success) {
      Serial.println("Failed to send image after multiple attempts. Aborting.");
      esp8266at.closeClientConnection(linkID);
    }

    digitalWrite(LED2, LOW);
    isTransmitting = false;  // Unlock transmission
    delay(200);              // Allow some time for the connection to settle
  } else {
    // Send a simple HTML response directing the user to the image URL
    String uri = "http://" + esp8266at.getLocalIP() + "/cam.jpg";
    String msg = "HTTP/1.1 200 OK\r\n";
    msg += "Content-Type: text/html\r\n";
    msg += "\r\n";
    msg += "<html>please access <a href='" + uri + "'>" + uri + "</a></html>\r\n";

    Serial.print(msg);
    esp8266at.sendMessageToClient(linkID, msg);
  }

  //Serial.println("Closing connection: " + linkID);
  //esp8266at.closeClientConnection(linkID);  // Ensure connection is closed properly
  isTransmitting = false;  // Unlock transmission
  delay(200);
}
