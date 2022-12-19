void setup(){
  Serial.begin(9600); //Ustawienie prędkości transmisji
  Serial.println("Monitoring okna"); //Jednorazowe wysłanie tekstu
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  
}
void loop() {
  if ( digitalRead(10) == LOW) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  else {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    Serial.println("Uwaga!, Alarm!, Okno nie jest zamkniete!");
    while (digitalRead(10) == HIGH ) {
      delay(25);
      }
  }
}
