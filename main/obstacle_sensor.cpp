#include "obstacle_sensor.h"

ObstacleSensor::ObstacleSensor(int trig, int echo, int maxDist)
    : trigPin(trig), echoPin(echo), maxDistance(maxDist), sonar(trig, echo, maxDist) {
}

int ObstacleSensor::getDistance() {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int d = sonar.ping_cm();
        if (d == 0) d = maxDistance;
        sum += d;
        delay(30); 
    }
    return sum / 3;
}