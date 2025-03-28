#include <NewPing.h>
#include <Servo.h>

// Emprant el ultrasonic i el servo calculem la direccio dels servos. Cointrolador tipus "bang bang", com un termostat
// cal afegir un PID
#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 400 // Maximum distance we want to measure (in centimeters).

Servo dir;


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600);
  dir.attach(5);

}

void loop() {
  delay(150);                    // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

  int distance = sonar.ping_cm(); // Send ping, get distance in cm and print result (0 = outside set distance range)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance > 6){ //si dist mes de 6, gira a un costat
    dir.write(140);
    Serial.println("mes");
  } 
  else if (distance < 6){ // si dist menys de 6, gira a l'altre
    dir.write(40);
    Serial.println("menos");
  }
  else{
    dir.write(90); // continua recte en el servo
    Serial.println("centre");
  }
}
