void setup(){
  Serial.begin(9600); //Ustawienie prędkości transmisji
  Serial.println("Witaj na Forbocie!"); //Jednorazowe wysłanie tekstu
  Serial.println("To ja Twoj port szeregowy: ");
}
void loop() {
  delay(5000);
  Serial.println("Minelo 5 sekund!"); //Wysyłanie w pętli
}
