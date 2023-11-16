int butt=8;
int buzzer=6;
int led=42;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(butt,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button=digitalRead(butt);
  if(button==HIGH)
  {
    Serial.println("ON");
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
  }
  else
  {
    Serial.println("OFF");
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }
  delay(10);
}
