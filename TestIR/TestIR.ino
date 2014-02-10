#include <Servo.h>

Servo panServo;
Servo tiltServo;

int analogPin = A0;     // IR rangefinder signal
int val = 0;           // variable to store the value read
float dist = 0;        // variable to store the calculated distance
float panPos = 0;      // variables to store the servo positions
float tiltPos = 0;
int tiltOff = 83;      //offset between actual straight ahead and
                       //servo 0 (tilt)
int panOff = -7;       //ofset between actual straight ahead and
                       //servo 90 (pan)
float stepSize = .8;

//Convert IR sensor reading to real distance
float getDist(int IRval) {
  return 4590*(1.0)/((float) IRval);
}

//Convert real world degrees to tilt servo position
//0 = straight ahead, 90 = straight up
int tiltEncode(int deg){
  return (-1*deg)+tiltOff;
}

//Convert real world degrees to pan servo position
//90 = straight ahead, 0 = straight right
int panEncode(int deg) {
  return deg+panOff;
}

//Take distance readings and average
int takeData() {
  int val = 0;
  int n = 10; //num of measurements to average
  int i = 0;
  for (i = 0; i<n; i+=1) {
    val += analogRead(analogPin);
    delay(5);
  }
  return val/n;
  
}


void setup()

{

  Serial.begin(9600);          
  panServo.attach(9);
  tiltServo.attach(10);
}



void loop()

{
  
  for(tiltPos = 25; tiltPos>-12; tiltPos -= stepSize) {
    tiltServo.write(tiltEncode(tiltPos));
    delay(100);//wait for tilt servo to move
    for(panPos = 50; panPos<110; panPos+=stepSize) {
      panServo.write(panEncode(panPos));
      delay(100); //wait or pan servo to move
      val = takeData(); //get data
      dist = getDist(val); 
      
      // Write csv format for copying
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
  //end of scan
  delay(10000);

}
