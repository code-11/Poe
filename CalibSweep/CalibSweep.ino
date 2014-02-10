#include <Servo.h>

Servo panServo;
Servo tiltServo;

float panPos = 0;
float tiltPos = 0;

void setup()

{

  Serial.begin(9600);          //  setup serial
  panServo.attach(9);
  tiltServo.attach(10);
}



void loop()

{
  Serial.println("tilt");
  float stepSize = .5;
  for(tiltPos = 60; tiltPos<100; tiltPos += stepSize) {
    tiltServo.write(tiltPos);
    delay(300);
    Serial.println(tiltPos);
  }
  Serial.println("pan");
  for(panPos = 70; panPos<100; panPos+=stepSize) {
    panServo.write(panPos);
    delay(300);
    Serial.println(panPos);             

  }
  delay(10000);

}
