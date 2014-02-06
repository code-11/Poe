#include <Servo.h>

Servo panServo;
Servo tiltServo;

int analogPin = A0;     // potentiometer wiper (middle terminal) connected to analog pin 3
int val = 0;           // variable to store the value read
float dist = 0;        // variable to store the calculated distance
float panPos = 0;           // variable to store the servo position
float tiltPos = 0;
int ahead = 70;

float getDist(int IRval) {
  return 4590*(1.0)/((float) IRval);
}

int motorEncode(int deg){
  return (-1*deg)+ahead;
}

int takeData() {
  int val = 0;
  int i = 0;
  for (i = 0; i<5; i+=1) {
    val += analogRead(analogPin);    // read the input pin
    delay(10);
  }
  return val/5;
  
}


void setup()

{

  Serial.begin(9600);          //  setup serial
  panServo.attach(9);
  tiltServo.attach(10);
}



void loop()

{
  for(tiltPos = motorEncode(25); tiltPos<motorEncode(-10); tiltPos += 2) {
    tiltServo.write(tiltPos);
    delay(100);
    for(panPos = 0; panPos<180; panPos+=2) {
      panServo.write(panPos);
      delay(100);
      val = takeData();
      dist = getDist(val);
      Serial.print(tiltPos);
      Serial.print(",");
      Serial.print(panPos);             
      Serial.print(",");
      Serial.print(val);
      Serial.print(",");
      Serial.println(dist);
    }
    delay(500);
  }
  delay(10000);

}
