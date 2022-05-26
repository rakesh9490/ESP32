// Use ESP32 with ADS1115 using standard connection with I2C (refer internet)
// Connect a NTC 10K thermistor and use 10k resistor as voltage divider

#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

void setup(void)
{
  Serial.begin(9600);
 // Serial.println("Hello!");

 // Serial.println("Getting single-ended readings from AIN0..3");
 // Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");

  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}

double Vs = 3.3;       // Reference voltage
double R1 = 10000.0;   // voltage divider resistor value
double Beta = 3977.0;  // Beta value (From datasheet/manufacturer)
double To = 298.15;    // Temperature in Kelvin for 25 degree Celsius
double Ro = 10000.0;   // Resistance of Thermistor at 25 degree Celsius

void loop() {
  int16_t adc0; // Temperature sensor connected to adc0 of ADS1115
  float volts0;

  double Vout, Rt = 0;
  double T, Tc, Tf = 0;

  adc0 = ads.readADC_SingleEnded(0); // Read the temperature sensor output
  volts0 = ads.computeVolts(adc0);   // Convert temperature to voltage

  Rt = R1 * volts0 / (Vs - volts0);  // Formula to obtain Rt

  T = 1/(1/To + log(Rt/Ro)/Beta);    // Temperature in Kelvin
  Tc = T - 273.15;                   // Celsius
  Tf = Tc * 9 / 5 + 32;              // Fahrenheit
  Serial.println(Tc);                // Serial print temperature
  delay(2000);
}
