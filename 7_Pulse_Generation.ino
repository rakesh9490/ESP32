const int ledPin1 = 23;  // 16 corresponds to GPIO16
// const int ledPin2 = 22;  // 16 corresponds to GPIO16


// setting PWM properties
const int freq1 = 2000;
const int ledChannel1 = 0;
const int resolution1 = 11;

// setting PWM properties
// const int freq2 = 39000;
// const int ledChannel2 = 0;
// const int resolution2 = 11;
 
void setup(){
  // configure LED PWM functionalitites
   ledcSetup(ledChannel1, freq1, resolution1);
//   ledcSetup(ledChannel2, freq2, resolution2);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin1, ledChannel1);
//   ledcAttachPin(ledPin2, ledChannel2);
}
 
void loop(){
  ledcWrite(ledChannel1, 1024);
// delay(1);
// ledcWrite(ledChannel2, 1024);
//  // increase the LED brightness
// for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
//    // changing the LED brightness with PWM
//    ledcWrite(ledChannel, dutyCycle);
//    delay(15);
//  }
//
//  // decrease the LED brightness
//   for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
//    // changing the LED brightness with PWM
//     ledcWrite(ledChannel, dutyCycle);   
//     delay(15);
//  }
}
