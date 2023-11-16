/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-flame-sensor
 */

#define DO_PIN 7  // ESP32's pin GPIO13 connected to DO pin of the flame sensor

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  // initialize the ESP32's pin as an input
  pinMode(DO_PIN, INPUT);
}

void loop() {
  int flame_state = digitalRead(DO_PIN);

  if (flame_state == LOW)
    Serial.println("No flame dected => The fire is NOT detected");
  else
    Serial.println("Flame dected => The fire is detected");
  delay(1000);
}
