//declaration
int led=42;

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(led,HIGH);
  Serial.println("1111");
  delay(2000);
  digitalWrite(led,LOW);
  Serial.println("0000");
  delay(2000);
}