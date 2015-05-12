#include <math.h>

// A partir de la salida del termistor calculamos la Tª
double Thermister(int RawADC) {
  double res, Vo, calculatedRes;
  Vo = (RawADC)*(3.3/4095.0);
  calculatedRes = 10000*(3.3/Vo-1);
  res = log(calculatedRes);
  res = 1 / (0.001126068758413 + ( 0.000234572594529 + (0.000000086312248 * res * res ))* res );
  res = res - 273.15;// Convert Kelvin to Celcius
  return res;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  double temperature;
  temperature = Thermister(analogRead(0));
  Serial.print(temperature);
  Serial.println(" ºC");
  delay(500);
}
