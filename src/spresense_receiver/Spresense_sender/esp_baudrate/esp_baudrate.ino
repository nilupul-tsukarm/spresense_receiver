#define NEW_BAUDRATE 2000000  // Set the new baud rate (115200, 921600, 2000000, etc.)

void setup() {
  Serial.begin(115200);   // Debug serial
  Serial2.begin(921600);  // ESP8266 communication at default baud rate

  Serial.println("Changing ESP8266 Baud Rate...");

  // Send AT command to change baud rate
  Serial2.println("AT+UART_DEF=" + String(NEW_BAUDRATE) + ",8,1,0,0");

  delay(500);  // Give some time for processing

  // Read response from ESP8266
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }

  Serial.println("\nBaud rate changed. Restarting ESP8266...");

  delay(1000);  // Short delay before restarting

  // Restart ESP8266
  Serial2.println("AT+RST");
  
  delay(1000);
  
  // Change Spresense Serial2 to match the new baud rate
  Serial2.begin(NEW_BAUDRATE);
  Serial.println("ESP8266 restarted, new baud rate set.");
}

void loop() {
  // Forward data between Serial Monitor and ESP8266 for debugging
  if (Serial.available()) {
    Serial2.write(Serial.read());
  }
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}
