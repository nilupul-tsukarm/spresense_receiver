#include <SPI.h>

void setup() {
  Serial.begin(115200);
  SPI5.begin();
  SPI5.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE3));
  Serial.println("Setup complete");
}


static inline int spigetb() {
  return SPI5.transfer(0) & 0xff;
}


static int spigeth() {
  int i;

  i = spigetb() << 8;
  i |= spigetb();
  return i;
}


static int spigetw() {
  int i;

  i = spigetb() << 24;
  i |= spigetb() << 16;
  i |= spigetb() << 8;
  i |= spigetb();
  return i;
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
  spiskip(256);
  delay(500);
  spicommand(0, 0xff);  // sync mode.
  delay(500);
  spiskip(256);
  spiskip(spigetb());  // sync.
  spicommand(0, 0);    // normal mode.
  delay(500);

  //  spicommand(0x10, 0x40); // 64frames/s
  //  spicommand(0x10, 0x80); // 128frames/s
  //spicommand(0x10, 0);  // 256frames/s
  //  spicommand(0x11, 0x40); // 320frames/s
  //spicommand(0x11, 1);  // 5frames/s
  spicommand(0x10, 0x01);  // Set frame rate to 1 FPS

  delay(500);
  spiskip(256);

  for (;;) {
    static int count = 0;
    static int oldseq = -1;
    static int ledr = 0;
    static int ledg = 0;
    static int ledb = 0;

    int magic0 = spigetb();
    int seq0 = spigetb();
    spiskip(2); /* ver h/l */
    int range = spigetw();

    //    spiskip(256 - 9);
    spicommandinner(0xc0, ledr);
    spicommandinner(0xc1, ledg);
    spicommandinner(0xc2, ledb);
    spiskip(256 - 9 - 5 * 3);

    int seq1 = spigetb();
    if (magic0 != 0xe9)
      continue;
    if (seq0 != seq1)
      continue;
    if (oldseq < 0)
      ;
    else if (((oldseq - seq0) & 0x80) == 0)
      continue;
    oldseq = seq0;
    int dis = range / (0x400000 / 1000);
    if (true) {
      Serial.print(count++);
      Serial.print("(");
      Serial.print(seq0, HEX);
      Serial.print("): ");

      Serial.print(dis);
      Serial.print("mm\n");
    }
    int i = dis & 0xff;
    switch (dis >> 8) {
      default:
        ledr = ledg = ledb = 0;
        break;
      case 6:
        ledr = 0;
        ledg = 0;
        ledb = 255 - i;
        break;
      case 5:
        ledr = 0;
        ledg = 255 - i;
        ledb = 255;
        break;
      case 4:
        ledr = 0;
        ledg = 255;
        ledb = i;
        break;
      case 3:
        ledr = 255 - i;
        ledg = 255;
        ledb = 0;
        break;
      case 2:
        ledr = 255;
        ledg = i;
        ledb = 0;
        break;
      case 1:
        ledr = 255;
        ledg = 0;
        ledb = 255 - i;
        break;
      case 0:
        ledr = 255;
        ledg = 255 - i;
        ledb = 255;
        break;
    }
    char c;
    switch (dis / 200) {
      case 0:
        c = 0;
        break;
      case 1:
        c = 1;
        break;
      case 2:
        c = 3;
        break;
      case 3:
        c = 7;
        break;
      case 4:
        c = 0xf;
        break;
      case 5:
        c = 0xe;
        break;
      case 6:
        c = 0xc;
        break;
      case 7:
      default:
        c = 8;
        break;
    }
    digitalWrite(LED0, (c & 1) ? HIGH : LOW);
    digitalWrite(LED1, (c & 2) ? HIGH : LOW);
    digitalWrite(LED2, (c & 4) ? HIGH : LOW);
    digitalWrite(LED3, (c & 8) ? HIGH : LOW);
  }
}
