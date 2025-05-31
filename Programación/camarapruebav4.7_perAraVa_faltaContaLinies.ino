#include "HUSKYLENS.h"
#include "SoftwareSerial.h"
#include "Servo.h"
//#define l 13

// defines ultrasonic pins numbers
Servo servo;

#define trig 10
#define echo  9
#define trig2  A1
#define echo2  A0
#define trig3  A3
#define echo3  A2

#define motorA 4
#define motorB 6
#define pwm 5
#define buttonPin 12

// defines variables
long duration;
int distance;
long duration2;
int distance2;
long duration3;
int distance3;
int buttonState=HIGH;
int color=0;
bool Bstart=1;
int dins=130;
int fora=66;
int ContaVoltes;
long DelayLine=0;
long MotorMillis=0;

HUSKYLENS huskylens;

//int ledPin = 13;
SoftwareSerial mySerial(10, 11); // RX, TX
//HUSKYLENS green line >> Pin 10; blue line >> Pin 11
void printResult(HUSKYLENSResult result);

void setup() {


  servo.attach(8);
  Serial.begin(115200);
  pinMode(trig, OUTPUT); // Sets the trig as an Output
  pinMode(echo, INPUT); // Sets the echo as an Input
  pinMode(trig2, OUTPUT); // Sets the trig as an Output
  pinMode(echo2, INPUT); // Sets the echo as an Input
  pinMode(trig3, OUTPUT); // Sets the trig as an Output
  pinMode(echo3, INPUT); // Sets the echo as an Input

  pinMode(buttonPin, INPUT); // Sets the button as an Input


  pinMode(pwm, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);

  //analogWrite(pwm, 250);

  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
  servo.write(96);

  int countButton = 0;
  while (countButton <= 10){

  buttonState = digitalRead(buttonPin);
  if (buttonState==LOW) countButton++;
  delay(10);
  }
  
  analogWrite(pwm, 96);
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);

  
// mySerial.begin(9600);


   Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
    servo.attach(8);
    ContaVoltes=0;
}

void loop() 
{
    if (!huskylens.request()) 
      Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));

    else if(!huskylens.isLearned()) 
      Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));

    else if(!huskylens.available()) 
    Serial.println(F("No block or arrow appears on the screen!"));


    else
    {
        //Serial.println(F("###########"));
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            printResult(result);
            //driveBot(result);
        }    
    }
    
  //analogWrite(pwm, 96);
  if (ContaVoltes>=12) {
    if((MotorMillis+1000)<=millis()) digitalWrite(motorA, LOW);    
    }
  else {
    digitalWrite(motorA, HIGH);
    MotorMillis=millis();}
  digitalWrite(motorB, LOW);
  //Serial.println("inicia");
  girar();
}

 

void printResult(HUSKYLENSResult result){

    int ID = result.ID;
   //clr(ID);
    if (result.command == COMMAND_RETURN_BLOCK){
        //Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        //Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }

}


void clr(int ID) {

        if ((ID == 1) ){// Serial.println("Taronja");
          if (Bstart){Bstart=0;dins=130;fora=62;}
          servo.write(dins); analogWrite(pwm, 106);
          delay(400);//servo.write(96);        
            
            } 	
        else {
          if ((ID == 3)){//  Serial.println("Blau");
          if (Bstart){Bstart=0;dins=62;fora=130;}
            servo.write(dins);analogWrite(pwm, 106);
          delay(400);//servo.write(96);

            }
          else{ 
            /*if (ID == 3){ // Serial.println("Roig");
              //servo.write(60);       
              }
            else{ 
              if (ID == 4){// Serial.println("verd");
              //servo.write(120);  }
              }
               else {*/ // Serial.println("ningun");
                servo.write(96); analogWrite(pwm, 80);
                }
    }

    delay(40);


}
int getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH,20000);
  if (duration == 0 ) duration = 20000;
  int distance = duration * 0.0343 / 2;
  return distance;
}

void girar (){
    int distanceFront = getDistance(trig3, echo3);
  //Serial.println(distanceFront);
  int distanceLeft = getDistance(trig2, echo2);
  //delay(10);
  int distanceRight = getDistance(trig, echo);
  //delay(10);
  
 /* if (distanceLeft <= 50){
    //analogWrite(pwm, 100);
    servo.write(135);
    delay(200);
    servo.write(95);
    analogWrite(pwm, 100);
  }
  else{
  if (distanceRight <= 50){
    //analogWrite(pwm, 100);
    servo.write(65);
    delay(200);
    servo.write(95);
    analogWrite(pwm, 100);
    }*/
  signed int dServo= (distanceRight-distanceLeft)>>1;
  if (dServo>40) dServo=40;
  if (dServo<-40) dServo=-40;
  servo.write (dServo+95);
  if (dServo>=0) analogWrite(pwm, 96+dServo);
  else analogWrite(pwm, 96-dServo);
 /*else{
  if (distanceFront <= 70){
    //analogWrite(pwm, 100);
    servo.write(125);
    delay(100);
    servo.write(95);
    analogWrite(pwm, 100);
  }
  else{
  servo.write(95);
  }}}*/
}