
#include <Servo.h>


// defines ultrasonic pins numbers
Servo servo;

#define trig 4
#define echo  2
#define trig2  7
#define echo2  6
#define trig3  9
#define echo3  8

#define motorA 12
#define motorB 13
#define pwm 3

// defines variables
long duration;
int distance;
long duration2;
int distance2;
long duration3;
int distance3;

void setup() {
  servo.attach(5);
  pinMode(trig, OUTPUT); // Sets the trig as an Output
  pinMode(echo, INPUT); // Sets the echo as an Input
  pinMode(trig2, OUTPUT); // Sets the trig as an Output
  pinMode(echo2, INPUT); // Sets the echo as an Input
  pinMode(trig3, OUTPUT); // Sets the trig as an Output
  pinMode(echo3, INPUT); // Sets the echo as an Input

  pinMode(pwm, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);

  analogWrite(pwm, 250);

  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);

  servo.write(90);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  analogWrite(pwm, 130 );
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);

  int distanceFront = getDistance(trig, echo);
  int distanceLeft = getDistance(trig2, echo2);
  int distanceRight = getDistance(trig3, echo3);

  if (distanceLeft <= 10){
    analogWrite(pwm, 155);
    servo.write(120);
    delay(800);
    servo.write(90);
    analogWrite(pwm, 255);
  }

  if (distanceRight <= 10){
    analogWrite(pwm, 155);
    servo.write(60);
    delay(800);
    servo.write(90);
    analogWrite(pwm, 255);
  }


}

int getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0343 / 2;
  return distance;
}