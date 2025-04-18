#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

#include <Arduino.h>
#include "motor_control.h"
void readSensors();
void handleLine();
void initSensors();

// Cảm biến
extern const int sensors[5];
extern int sensorValues[5];

extern MotorControl motor;

#endif
