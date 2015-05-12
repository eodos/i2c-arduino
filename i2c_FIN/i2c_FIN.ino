#include <Wire.h>
#include <math.h>
 
#define SLAVE_ADDRESS 0x04
#define TAG_TEMP "TEMP"
#define TAG_RAIN "RAIN"

String var;
char c;
int value;
double temperature;
int rain;
String temp;
char char_array[] = "";
 
// configuracion inicial
void setup() {
  // inicializamos i2c como esclavo
  Wire.begin(SLAVE_ADDRESS);
  
  // llamadas para la comunicacion
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}
 
// bucle principal
void loop() {}

// llamada para recibir datos
void receiveData(int byteCount) {
  
  var = "";
  
  while (Wire.available() > 0) {
    c = Wire.read();
    var.concat(c);
  }
      
  if (var == TAG_TEMP) {
    temperature = Thermister(analogRead(0)) *100;
    value = (int) temperature; 
  }
  
  else if (var == TAG_RAIN) {
    rain = digitalRead(50);
    value = rain;   
  }
  
  // Convert int to char*
  temp = (String) value;
  unsigned int temp_length = temp.length()+1;
  ((String)temp).toCharArray(char_array, temp_length);
  
}
 
// llamada para enviar datos
void sendData() {
  Wire.write(char_array);
}

double Thermister(int voltaje) {
  double Temp;
  Temp = log(((10240000/voltaje) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;
  return Temp;
}
