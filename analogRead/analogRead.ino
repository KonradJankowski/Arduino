int odczytywanaWartosc = 0;
float napiecie = 0; //Wartość przeliczona na napięcie w V

void setup() {
  Serial.begin(9600); //Ustawienie prędkości transmisji
  Serial.println(" ");

}

void loop() {
  odczytywanaWartosc = analogRead(A5);
  napiecie = odczytywanaWartosc * (5.0/1023.0);
  Serial.print(napiecie);
  Serial.println(" V");
  delay(200);
}
