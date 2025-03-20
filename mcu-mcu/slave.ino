#include <Wire.h> // Include the Wire library for I2C

int ledPin = 11; // LED connected to pin 11 (PWM capable)
int potVal = 0;  // Variable to store the received potentiometer value

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Wire.begin(0x27);        // Start the I2C Bus as Slave on address 0x27
  Wire.onReceive(receiveEvent); // Register event for receiving data
  Wire.onRequest(requestEvent); // Register event for sending data
  Serial.begin(9600);      // Start serial communication for debugging
}

void loop() {
  // Map the potentiometer value (0–1023) to PWM range (0–255)
  int pwmValue = map(potVal, 0, 1023, 0, 255);
  analogWrite(ledPin, pwmValue); // Control LED brightness
}

// Function that executes whenever data is received from the master
void receiveEvent(int bytes) {
  if (Wire.available() >= 2) { // Ensure we receive 2 bytes
    byte byte1 = Wire.read();  // Read low byte
    byte byte2 = Wire.read();  // Read high byte
    potVal = (byte2 << 8) | byte1; // Combine bytes into 10-bit value
    Serial.print("Received: ");
    Serial.println(potVal);    // Print received value
  }
}

// Function that executes whenever data is requested by the master
void requestEvent() {
  char data[] = "Hello!";      // Data to send (6 bytes)
  Wire.write(data, 6);         // Send 6 bytes to master
}