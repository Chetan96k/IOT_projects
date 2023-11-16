//Write controller
#include <Wire.h>
int ir=8;
int led=42;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); 
  pinMode(led,OUTPUT);// register event
  pinMode(ir,INPUT);
}

void loop() {
  delay(1000);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  int data = digitalRead(ir);
  if(data==HIGH)
  {
    Wire.write('1');
  }
  else
  {
    Wire.write('0');
  }
  digitalWrite(led,HIGH);
  delay(2000);
  digitalWrite(led,LOW);
  // respond with message of 6 bytes
  // as expected by master
}