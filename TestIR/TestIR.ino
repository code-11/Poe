int analogPin = A0;     // potentiometer wiper (middle terminal) connected to analog pin 3

                       // outside leads to ground and +5V

int val = 0;           // variable to store the value read
float dist = 0;


float getDist(int IRval) {
  return 4590*(1.0)/((float) IRval);
}

void setup()

{

  Serial.begin(9600);          //  setup serial

}



void loop()

{

  val = analogRead(analogPin);    // read the input pin
  
  dist1 = getDist(val);

  Serial.println(val);             // debug value
  Serial.println(dist);

}
