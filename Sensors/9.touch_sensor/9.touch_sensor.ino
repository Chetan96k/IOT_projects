int DO_PIN=8 ; // ESP32's pin GPIO13 connected to DO pin of the flame sensor
int buzzer=6;

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  // initialize the ESP32's pin as an input
  pinMode(DO_PIN, INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  int touch = digitalRead(DO_PIN);

  if (touch == HIGH)
  {
    Serial.println("Touch detected");
    digitalWrite(buzzer,HIGH);
  }
  else
  {
     Serial.println("Touch not detected");
     digitalWrite(buzzer,LOW);
  }
  delay(1000);
}