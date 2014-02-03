#include <Servo.h>

Servo myservo;

int analogPin = A0;     // potentiometer wiper (middle terminal) connected to analog pin 3
int val1 = 0;           // variable to store the value read
int val2 = 0;
int val3 = 0;
float dist = 0;        // variable to store the calculated distance
float pos = 0;           // variable to store the servo position
//float tiltPos = 0;

float getDist(int IRval) {
  return 4590*(1.0)/((float) IRval);
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
    val1 = analogRead(analogPin);    // read the input pin
    delay(10);
    val2 = analogRead(analogPin);
    delay(10);
    val3 = analogRead(analogPin);
    dist = getDist((val1+val2+val3)/3);
    Serial.print(pos);             
    Serial.print(",");
    Serial.print((val1+val2+val3)/3);
    Serial.print(",");
    Serial.println(dist);
  }
  myservo.write(0);
  delay(10000);

}
