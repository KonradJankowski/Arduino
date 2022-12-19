#include <LiquidCrystal.h> //Dołączenie biblioteki
LiquidCrystal lcd(2,3,4,5,6,7); //Informacja o podłączeniu wyswietlacza
int speed = 0; //predkosc silnika, zmienna globalna, całkowita

void setup() { 
  lcd.begin(16,2); //Deklaracja typu LCD
  lcd.setCursor(0,0);  //Ustawienie kursora
  lcd.print("Sterownik Oprysk");
  lcd.setCursor(0,1);
  lcd.print("Konrad Jankowski");
  delay(2000);  //opóźnienie 2 sekundy
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("STOP / UP / DOWN");
  pinMode(10, OUTPUT); //Sygnał PWM silnika nr 1
  pinMode(11, INPUT_PULLUP);  //przycisk DOWN
  pinMode(12, INPUT_PULLUP);  //przycisk UP
  pinMode(13, INPUT_PULLUP);  //przycisk STOP
  pinMode(8, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(9, OUTPUT); //
  
} 
 
void loop()  {   
  if (digitalRead(13) == HIGH) {      //awaryjne wyłączenie - STOP
 
    if (digitalRead(12) == LOW) {     // zwiększanie prędkości, przycisk UP
      if (speed < 201) {
        speed = speed + 50;
        delay(200);
      }
    }
    if (digitalRead(11) == LOW) {     // zmniejszenie prędkości, przycisk DOWN
      if (speed > 49) {
        speed = speed - 50;
        delay(200);
        if (speed == 50) {
          lcd.setCursor(0,1);
          lcd.print("                ");
        }
      }
    }
    
  analogWrite(10, speed);  //aktualna prędkość
  digitalWrite(8, HIGH); //Silnik nr 1 - obroty w prawo
  digitalWrite(9, LOW);
  lcd.setCursor(0,1);
  lcd.print("Szybkosc:");
  lcd.setCursor(10,1);
  lcd.print(speed);     
  }
  else {
      digitalWrite(8, LOW); //Silnik nr 1 - obroty na luz
      digitalWrite(9, LOW);
      while (digitalRead(13) == LOW) {    // komunikat przy awaryjnym wyłączeniu
        lcd.setCursor(0,1);
        lcd.print("Wcisniety STOP!!");
        delay(500);
        lcd.setCursor(0,1);
        lcd.print("                ");
        delay(500);
      }                           
  }
}
