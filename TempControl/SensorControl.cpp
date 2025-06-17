#include "SensorControl.h"

#define Environment Environment_I2C
const int motorPin = 8;  // Motor pin def.

void setupSensor() {
  Wire.begin();
  Environment.begin();
}

float readTemperature() {
  return Environment.readTemperature();
}