#include "Arduino_SensorKit.h"

#define Environment Environment_I2C

const int motorPin = 8; // Pin connected to motor

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  Environment.begin();

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() 
{
  // === Read Serial Input for LED Control ===
  if (Serial.available() > 0) {
    char simbols = Serial.read(); // Read 1 byte from serial

    Serial.println(simbols, DEC);

    if (simbols == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (simbols == '0') {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  float temp = Environment.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println(" C");

  if (temp >= 26.0) {  // HIGH temperature threshold
    digitalWrite(motorPin, HIGH); // Turn on motor
    Serial.println("Motor ON - High temperature");
  } else {
    digitalWrite(motorPin, LOW);  // Turn off motor
    Serial.println("Motor OFF - Temperature normal");
  }

  delay(2000);
}