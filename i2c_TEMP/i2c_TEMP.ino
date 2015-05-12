#include <Wire.h>
#include <math.h>
 
#define SLAVE_ADDRESS 0x04

String TAG_TEMP = "TEMP";
String var;
char c;
int value;
double temperature;
String temp;
char char_array[] = "";
 
// configuracion inicial
void setup() {
  // puerto serie
  Serial.begin(9600);
  
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
  
  Serial.println(var);
  Serial.println(var.length());
    
  if (var == TAG_TEMP) {
    Serial.println("TEMP request received");
    temperature = Thermister(analogRead(0)) *100;
    Serial.println(temperature);
       
    // Convert double to char*
    value = (long int) temperature; 
    temp = (String) value;
    unsigned int temp_length = temp.length()+1;
    ((String)temp).toCharArray(char_array, temp_length);
  }
}
 
// llamada para enviar datos
void sendData() {
  Wire.write(char_array);
  Serial.print("sent: ");
  Serial.println(char_array);
}

double Thermister(int voltaje) {
  double Temp;
  Temp = log(((10240000/voltaje) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;
  return Temp;
}
