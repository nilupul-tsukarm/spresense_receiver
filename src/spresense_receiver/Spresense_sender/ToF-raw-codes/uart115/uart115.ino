#include <Arduino.h>

// Command to activate the sensor
const char activateCommand[] = "EB 00 01 00 ED";

void setup() {
  Serial.begin(115200);  // Debugging via Serial Monitor
  Serial2.begin(115200); // UART communication with MM-S50MV sensor

  // Send the activation command
  sendActivateCommand();
}

void loop() {
  static String dataBuffer = "";  // Buffer to accumulate incoming UART data
  while (Serial2.available()) {
    char incomingChar = Serial2.read();
    if (incomingChar == '\n') {  // End of a data block
      processSensorData(dataBuffer);  // Process the data
      dataBuffer = "";  // Clear the buffer for the next line
    } else if (incomingChar != '\r') {  // Ignore carriage returns
      dataBuffer += incomingChar;
    }
  }
}

// Function to send the activation command to the sensor
void sendActivateCommand() {
  Serial2.print(activateCommand);  // Send as a string
  delay(500); // Wait for the sensor to initialize
}

// Function to parse and extract the distance
void processSensorData(const String& data) {
  Serial.println("Raw Data: " + data);  // Debugging: Show raw data

  // Tokenize the raw data and print each field
  int fieldIndex = 0;
  String token = "";

  for (unsigned int i = 0; i <= data.length(); i++) {
    char c = data[i];
    if (c == '\t' || c == ',' || i == data.length()) {  // Detect delimiters or end of string
      Serial.print("Field ");
      Serial.print(fieldIndex + 1);
      Serial.print(": ");
      Serial.println(token);  // Print the token for debugging

      fieldIndex++;
      if (fieldIndex == 4) {  // Check the 4th field for distance
        float distance = token.toFloat();
        Serial.print("Parsed Distance: ");
        Serial.println(distance, 6);
      }

      token = "";  // Reset token for the next field
    } else {
      token += c;  // Build the token
    }
  }

  if (fieldIndex < 4) {
    Serial.println("Error: Insufficient fields in data.");
  }
}
