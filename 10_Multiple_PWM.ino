const int redLEDPin = 23;  /* GPIO16 */
// const int greenLEDPin = 22;  /* GPIO17 */

// uint16_t redDutyCycle;
// uint16_t greenDutyCycle;


const int redPWMFreq = 5000; /* 5 KHz */
const int redPWMChannel = 0;
const int redPWMResolution = 16;
// const int RED_MAX_DUTY_CYCLE = (int)(pow(2, redPWMResolution) - 1);

// const int greenPWMFreq = 5000; /* 8 KHz */
// const int greenPWMChannel = 2;
// const int greenPWMResolution = 16;
// const int GREEN_MAX_DUTY_CYCLE = (int)(pow(2, greenPWMResolution) - 1);

// const int ADC_RESOLUTION = 4095; /* 12-bit */


void setup()
{  
  /* Initialize Serial Port */
  Serial.begin(115200);
  /* Initialize PWM Channels with Frequency and Resolution */
  ledcSetup(redPWMChannel, redPWMFreq, redPWMResolution);
//  ledcSetup(greenPWMChannel, greenPWMFreq, greenPWMResolution);

  /* Attach the LED PWM Channel to the GPIO Pin */
  ledcAttachPin(redLEDPin, redPWMChannel);
//  ledcAttachPin(greenLEDPin, greenPWMChannel);
}
void loop()
{
  /* Read Analog Input from three ADC Inputs */
  // redDutyCycle = analogRead(A0);
  // greenDutyCycle = analogRead(A3);
  /* Map ADC Output to maximum possible dutycycle */
  // redDutyCycle = map(redDutyCycle, 0, ADC_RESOLUTION, 0, RED_MAX_DUTY_CYCLE);
  // greenDutyCycle = map(greenDutyCycle, 0, ADC_RESOLUTION, 0, GREEN_MAX_DUTY_CYCLE);
  /* Set PWM Output of Channel with desired dutycycle */ 
  ledcWrite(redPWMChannel, 1024);
//  ledcWrite(greenPWMChannel, 1024);

  //Serial.println("RED -- GREEN");
  //Serial.print(redDutyCycle);
  //Serial.print(" -- ");
  //Serial.print(greenDutyCycle);
  //Serial.print(" -- ");

  delay(1000);
}
