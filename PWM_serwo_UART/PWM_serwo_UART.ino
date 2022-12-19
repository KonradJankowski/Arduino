#include <Servo.h>

Servo serwomechanizm;  //Tworzę obiekt
String odebraneDane = "";
int pozycja = 10;

void setup() {
  Serial.begin(9600); 
  Serial.println("Witaj, podaj położenie serwa z zakresu 0 - 180");
  serwomechanizm.attach(3);   //Serwomechanizm podłączony do pinu 3

}

void loop() {
  if(Serial.available() > 0) {
    odebraneDane = Serial.readStringUntil('\n');
    pozycja = odebraneDane.toInt();

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
}

