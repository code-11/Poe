#include <Servo.h>

Servo myservo;

int analogPin = A0;     // potentiometer wiper (middle terminal) connected to analog pin 3
int val = 0;           // variable to store the value read
float dist = 0;        // variable to store the calculated distance
float pos = 0;           // variable to store the servo position
//float tiltPos = 0;

float getDist(int IRval) {
  return 4590*(1.0)/((float) IRval);
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
  myservo.attach(9);
  //tiltServo.attach(10);
}



void loop()

{
  for(pos = 0; pos<180; pos+=.5) {
    myservo.write(pos);
    delay(100);
    val = takeData();
    dist = getDist(val);
    Serial.print(pos);             
    Serial.print(",");
    Serial.print(val);
    Serial.print(",");
    Serial.println(dist);
  }
  myservo.write(0);
  delay(10000);

}
