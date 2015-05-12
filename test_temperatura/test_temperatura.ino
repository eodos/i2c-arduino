#include <math.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  double temperature;
  temperature = Thermister(analogRead(0));
  Serial.print(temperature);
  Serial.println(" C");
  delay(500);
}

// A partir de la salida del termistor calculamos la temperatura
double Thermister(int voltaje) {
  double Temp;
  Temp = log(((10240000/voltaje) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;
  return Temp;
}
