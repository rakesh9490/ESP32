#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.print("Hello from the setup");
  // put your setup code here, to run once:
}

void loop() {
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Hello from the loop");
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
  // put your main code here, to run repeatedly:
}