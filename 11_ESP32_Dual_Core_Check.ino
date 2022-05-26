// Explanations at https://randomnerdtutorials.com/esp32-dual-core-arduino-ide/
// Check the default core under which the ESP32 is running

void setup() {
  Serial.begin(115200);
  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
}

void loop() {
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());
}
