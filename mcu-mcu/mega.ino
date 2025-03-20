#include <Wire.h> // Include the Wire library for I2C

int potPin = A0;  // Potentiometer connected to analog pin A0
int potVal = 0;   // Variable to store the potentiometer value

void setup() {
  Wire.begin();       // Start the I2C Bus as Master
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Read the potentiometer value (0–1023)
  potVal = analogRead(potPin);

  // Split the 10-bit value into two bytes
  byte byte1 = potVal & 0xFF;         // Low byte
  byte byte2 = (potVal >> 8) & 0xFF;  // High byte

  // Send the potentiometer value to the slave (device #0x27)
  Wire.beginTransmission(0x27); // Transmit to device #0x27
  Wire.write(byte1);            // Send low byte
  Wire.write(byte2);            // Send high byte
  Wire.endTransmission();       // Stop transmitting

  // Request 6 bytes from the slave (device #0x27)
  Wire.requestFrom(0x27, 6);   // Request 6 bytes from slave device #0x27
  while (Wire.available()) {   // Slave may send less than requested
    char x = Wire.read();      // Receive a byte as a character
    Serial.print(x);           // Print the character
  }
  Serial.println();            // New line after receiving data

  delay(500); // Delay for stability
}