#ifndef SENSOR_CONTROL_H
#define SENSOR_CONTROL_H

#include <Arduino.h>
#include "Arduino_SensorKit.h"

extern const int motorPin;

void setupSensor();
float readTemperature();

#endif