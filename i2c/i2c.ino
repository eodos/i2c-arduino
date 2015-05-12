#include <Wire.h>
 
#define SLAVE_ADDRESS 0x04

int number = 0;
int state = 0;
 
// configuracion inicial
void setup() {
  pinMode(13, OUTPUT);
  // inicializamos i2c como esclavo
  Wire.begin(SLAVE_ADDRESS);
  // llamadas para la comunicacion
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}
 
// bucle principal (vacio)
void loop() {}

// llamada para recibir datos
void receiveData(int byteCount) {
  while(Wire.available()) {
    number = Wire.read();
    if (number == 1) {
      if (state == 0) {
        digitalWrite(13, HIGH); // set the LED on
        state = 1;
      } 
      else {
        digitalWrite(13, LOW); // set the LED off
        state = 0;
      }
    }
  }
}
 
// llamada para enviar datos
void sendData() {
  Wire.write(number);
}
