#ifndef OBSTACLE_SENSOR_H
#define OBSTACLE_SENSOR_H

#include <Arduino.h>
#include <NewPing.h>

class ObstacleSensor {
public:
    ObstacleSensor(int trigPin, int echoPin, int maxDistance);
    int getDistance();

private:
    int trigPin, echoPin, maxDistance;
    NewPing sonar;
};

#endif