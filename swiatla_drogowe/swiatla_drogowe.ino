
void setup() {
  Serial.begin(9600);
  Serial.println("Program do sterowania swiatami: ");
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

}

void loop() {
  while (digitalRead(7) == HIGH) { }
  digitalWrite(10, LOW); //Czerwona
  digitalWrite(9, LOW); //Pomarańczowa
  digitalWrite(8, HIGH); //Zielona 
  Serial.println("Teraz swieci sie dioda: Zielona");
 
   delay(400); //Czekamy 1 sekundę

 while (digitalRead(7) == HIGH) { }
  digitalWrite(10, LOW); //Czerwona
  digitalWrite(9, HIGH); //Pomarańczowa
  digitalWrite(8, LOW); //Zielona
  Serial.println("Teraz swieci sie dioda Pomaranczowa");
 
  delay(400); //Czekamy 1 sekundę

  while (digitalRead(7) == HIGH) { }
  digitalWrite(10, HIGH); //Czerwona
  digitalWrite(9, LOW); //Pomarańczowa
  digitalWrite(8, LOW); //Zielona
  Serial.println("Teraz swieca sie dioda: Czerwona");
 
   delay(400); //Czekamy 1 sekundę

  while (digitalRead(7) == HIGH) { }
  digitalWrite(10, HIGH); //Czerwona
  digitalWrite(9, HIGH); //Pomarańczowa
  digitalWrite(8, LOW); //Zielona
  Serial.println("Teraz swieca sie diody: Czerwona i Pomaranczowa");

  while (digitalRead(7) == HIGH) { }
   delay(400); //Czekamy 1 sekundę
  

}
