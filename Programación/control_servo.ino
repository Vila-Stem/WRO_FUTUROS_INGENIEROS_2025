
#include <Servo.h>


// defines ultrasonic pins numbers
Servo servo;

#define trig A5
#define echo  A4
#define trig2  A1
#define echo2  A0
#define trig3  A3
#define echo3  A2

#define motorA 4
#define motorB 6
#define pwm 5

// defines variables
long duration;
int distance;
long duration2;
int distance2;
long duration3;
int distance3;

void setup() {
  
  servo.attach(3);
  pinMode(trig, OUTPUT); // Sets the trig as an Output
  pinMode(echo, INPUT); // Sets the echo as an Input
  pinMode(trig2, OUTPUT); // Sets the trig as an Output
  pinMode(echo2, INPUT); // Sets the echo as an Input
  pinMode(trig3, OUTPUT); // Sets the trig as an Output
  pinMode(echo3, INPUT); // Sets the echo as an Input

  pinMode(pwm, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);

  //analogWrite(pwm, 250);

  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);

  servo.write(90);
  Serial.begin(115200); // Starts the serial communication
  analogWrite(pwm, 150);
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);
}
void loop() {
  /*servo.write(90);//analogWrite(pwm, 50 );
  delay(1000);
  servo.write(30);//analogWrite(pwm, 170 );
  delay(1000);
  servo.write(90);//analogWrite(pwm, 50 );
  delay(1000);
  servo.write(150);//analogWrite(pwm, 240 );
  delay(1000);*/
  
  

  int distanceFront = getDistance(trig3, echo3);
  //Serial.println(distanceFront);
  

  int distanceLeft = getDistance(trig2, echo2);
  //delay(10);
  int distanceRight = getDistance(trig, echo);
  //delay(10);
  

  
  if (distanceLeft <= 20){
    //analogWrite(pwm, 100);
    servo.write(125);
    //delay(80);
    //servo.write(95);
    //analogWrite(pwm, 100);
  }
  else{
  if (distanceRight <= 20){
    //analogWrite(pwm, 100);
    servo.write(70);
    //delay(80);
    //servo.write(95);
    //analogWrite(pwm, 100);
    }
  else{
  if (distanceFront <= 70){
    //analogWrite(pwm, 100);
    servo.write(125);
    //delay(100);
    //servo.write(95);
    //analogWrite(pwm, 100);
  }
  else{
  servo.write(95);
  }}}


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