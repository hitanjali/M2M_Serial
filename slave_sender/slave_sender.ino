// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
const byte nodeId = 10;
byte ledState = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin(nodeId);                // join i2c bus with address as defined above
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(500); 
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  ledState = !ledState;
  Wire.write(ledState); // respond with message of led state change
  Serial.println("Recived request from master");
  // as expected by master
}
