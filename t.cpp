#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

//our L298N control pins
const int LeftMotorForward = 13; // banh ben trai tien
const int LeftMotorBackward = 12; // banh ben trai lui
const int RightMotorForward = 11; // banh ben phai tien
const int RightMotorBackward = 10; // banh ben phai lui

const int ena = 6; 
const int enb = 5;

//sensor pins SR04
#define trig_pin 7 
#define echo_pin 4

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name

void setup(){
Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

 pinMode(ena, OUTPUT);
 pinMode(enb, OUTPUT);
  
  servo_motor.attach(9); //our servo pin

  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

 analogWrite(ena, 200);  // chinh toc do dong co ben trai
 analogWrite(enb, 200); // chinh toc do dong co ben trai

}

void loop(){
  
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop(); // dung lai
    delay(300);
    moveBackward(); // lui ve sau
    delay(400);
    moveStop();// dung lai
    delay(300);
    distanceRight = lookRight(); // lay khoang cach ben trai
    delay(300);
    distanceLeft = lookLeft(); // lay khoang cach ben phai
    delay(300);

    if (distance >= distanceLeft){ // neu khoang cach toi da >= khoang cach ben trai 
      turnRight(); //re phai
      moveStop();
    }
    else{ // ko thi
      turnLeft(); // re trai
      moveStop();
    }
  }
  else{
    moveForward();  // ko phai 2 truong hop tren thi chay thang
  }
    distance = readPing();
}

int lookRight(){  // nhin phai lay khoang cach
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){ // nhin trai lai khoang cach 
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){ // dung lai
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){ // di thang

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);

  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(RightMotorForward, LOW);
  
  delay(300);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(300);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}