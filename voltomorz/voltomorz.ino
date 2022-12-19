int odczytywanaWartosc = 0;
float napiecie = 0; //Wartość przeliczona na napięcie w V

void setup() {
  Serial.begin(9600); //Ustawienie prędkości transmisji
  Serial.println(" ");
  pinMode(2, OUTPUT);

}

void loop() {
  odczytywanaWartosc = analogRead(A5);
  digitalWrite(2, HIGH);
  delay(odczytywanaWartosc);
  digitalWrite(2,LOW);
  delay(odczytywanaWartosc);
  napiecie = odczytywanaWartosc * (5.0/1023.0);
  Serial.print(napiecie);
  Serial.println(" V");
  delay(200);
}
