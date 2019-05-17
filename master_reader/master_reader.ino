// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

// Output pins 
const byte node8 = 2;
const byte node9 = 3;
const byte node10 = 4;

//  Input pins

void setup() {

  pinMode(node8,OUTPUT);
  pinMode(node9,OUTPUT);
  pinMode(node10,OUTPUT);

  digitalWrite(node8,0);
  digitalWrite(node9,0);
  digitalWrite(node10,0);

  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
  Serial.println("Asking for data from node 8");
  while (Wire.available()) { // slave may send less than requested
    byte ledState = Wire.read(); // receive a byte as character
    digitalWrite(node8,ledState); // Write LED based on the input recieved
    Serial.println(ledState);         // print the character
    
  }
  
  Wire.requestFrom(9,1);    // request from device #9
  Serial.println("Asking for data from node 9");
  while (Wire.available()) { // slave may send less than requested
    byte ledState = Wire.read(); // receive a byte as character
    digitalWrite(node9,ledState); // Write LED based on the input recieved
    Serial.println(ledState);         // print the character
  }

  Wire.requestFrom(10,1);    // request from device #9
  Serial.println("Asking for data from node 10");
  while (Wire.available()) { // slave may send less than requested
    byte ledState = Wire.read(); // receive a byte as character
    digitalWrite(node10,ledState); // Write LED based on the input recieved
    Serial.println(ledState);         // print the character
  }

  delay(2000);
}
