#include <math.h> //Librería para usar logaritmos
#include <LiquidCrystal.h> //Librería LCD
#include <SFE_BMP180.h> //Librería presión
#include <Wire.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //Configuración del LCD
SFE_BMP180 presion; //Creamos el objeto

// A partir de la salida del termistor calculamos la Tª
double Thermister(int voltaje) 
{
  double Temp;
  Temp = log(((10240000/voltaje) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;
  return Temp;
}

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.setCursor(0,1);
  lcd.print("P: ");
}

void loop()
{
  lcd.setCursor(10,0);
  lcd.print(Thermister(analogRead(10)));
  delay(1000);
}
