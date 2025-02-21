#include "obstacle_avoidance.h"

ObstacleAvoidance::ObstacleAvoidance(MotorControl* m, ObstacleSensor* s) {
    motor = m;
    sensor = s;
}

void ObstacleAvoidance::checkAndAvoid() {
    int distanceFront = sensor->getDistance();
    delay(50);

    if (distanceFront > 150) {
          motor->moveForward(180);
    } else if (distanceFront >= 20) {
          motor->moveForward(150);
    } else {
          motor->moveStop();
          delay(100);

          motor->moveBackward(120);
          delay(500);
          motor->moveStop();

          motor->turnRight(150);
          delay(600);

          int distanceRight = sensor->getDistance();
          if (distanceRight > 20) {
              return;
          }

          motor->turnLeft(150);
          delay(1200);

          int distanceLeft = sensor->getDistance();
          if (distanceLeft > 20) {
              return;
          }

          motor->moveBackward(120);
          delay(1000);
          motor->moveStop();
    }
}

