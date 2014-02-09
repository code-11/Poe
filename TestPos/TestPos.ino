#include <Servo.h>

Servo panServo;
Servo tiltServo;

float panPos = 83;
float tiltPos = 68;

void setup()

{

  Serial.begin(9600);          //  setup serial
  panServo.attach(9);
  tiltServo.attach(10);
}



void loop()

{
    tiltServo.write(tiltPos);
    panServo.write(panPos);           

  delay(10000);

}
