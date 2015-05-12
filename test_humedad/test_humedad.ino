void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("D: ");
  Serial.println(digitalRead(50));
  Serial.print("A: ");
  Serial.println(analogRead(15));
  delay(1000);
}
