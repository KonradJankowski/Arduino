void setup() {
  pinMode(3, OUTPUT); //Konfiguracja pinu 3 jako wyjście
}
 
void loop() {
  digitalWrite(3, HIGH); //Włączenie diody
  delay(1667);
  digitalWrite(3, LOW); //Wyłączenie diody
  delay(333);
}
