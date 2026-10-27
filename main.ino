#include <math.h>

float coeffA = 1.150052470e-3, coeffB = 2.306227864e-4, coeffC = 1.021987840e-7;
float lnResistance, inverseTemp, tempKelvin, tempCelsius, sensorVoltage, thermistorResistance;
int sensorPin = A1;
int ledPin = 9;
 
void setup() {
  pinMode(sensorPin, INPUT); // for voltage divider
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // for LED
}

void loop() { 
  int rawValue = analogRead(sensorPin); // read raw ADC value

  sensorVoltage = 5. * rawValue / 1023; // convert to 0-5V

  thermistorResistance = sensorVoltage * 82000 / (5. - sensorVoltage); // calculate resistance

  lnResistance = log(thermistorResistance);

  inverseTemp = coeffA + coeffB * lnResistance + coeffC * pow(lnResistance, 3); 
  tempKelvin = 1 / inverseTemp; // substitute in equation
  tempCelsius = tempKelvin - 273; // convert to Celsius
  
  Serial.print("TEMP:");
  Serial.println(tempCelsius);
  
  Serial.print("led:");
  int ledBrightness = 17 * (tempCelsius - 20); // convert to light intensity
  Serial.println(ledBrightness);
  
  analogWrite(ledPin, ledBrightness);

  delay(1000);
}
