int led = 42;
int sound_sensor = 8;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(sound_sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound = digitalRead(sound_sensor);
  if(sound==HIGH)
  {
    Serial.println("sound detected");
    digitalWrite(led,HIGH);
  }
  else
  {
    Serial.println("sound not detected");
    digitalWrite(led,HIGH);
  }
  delay(500);
}
