#include <Servo.h>;

Servo serwomechanizm;
int odczytanaWartosc = 0;
int pozycja = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Sterój serwem za pomocą potencjometru");
  serwomechanizm.attach(3);

}

void loop() {
  odczytanaWartosc = analogRead(A5);
  delay(200);
  pozycja = (odczytanaWartosc / 6);
  pozycja += 5;
  if (pozycja <= 180) {               //Jeśli pozycja mieści się w zakresie
      serwomechanizm.write(pozycja);    //Wykonaj ruch
      Serial.print("Ustawiam servo w pozycji: ");
      Serial.print(pozycja);
      Serial.println(" stopni");
    }  else {
      Serial.println("Podana wartosc spoza zakresu !!!");
      Serial.println("Podaj poprawny zakres");
    }
}
