#include "SensorControl.h"

void setup() {
  Serial.begin(9600);
  setupSensor();
  pinMode(motorPin, OUTPUT);
}

void loop() {
  float temp = readTemperature();
  Serial.print("Temp: ");
  Serial.println(temp);

  if (temp >= 30.0) {
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor ON");
  } else {
    digitalWrite(motorPin, LOW);
    Serial.println("Motor OFF");
  }

  delay(2000);
}