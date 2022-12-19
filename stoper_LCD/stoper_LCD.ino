#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
double licznik = 0.00;
int start = 0;

void setup() {
  pinMode(8, INPUT_PULLUP);  //przycisk start
  pinMode(9, INPUT_PULLUP);  //przycisk stop
  pinMode(10, INPUT_PULLUP);  //przycisk reset
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RESET/START/STOP");
  lcd.setCursor(0,1);
  lcd.print("Stoper ver: 1.1 ");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("Konrad Jankowski");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("nacisnij przycisk");


}

void loop() {
  if (digitalRead(8) == LOW) {
    start = 1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RESET <- -> STOP");
  }

  while (start == 1)  {
    lcd.setCursor(5,1);
    lcd.print(licznik);
    licznik = licznik + 0.1;
    delay(100);
      if (digitalRead(9) == LOW){
       start = 0;
         lcd.setCursor(0,0);
         lcd.print("RESET/START/ <- ");
         lcd.setCursor(0,1);
         lcd.print("                ");
         lcd.setCursor(5,1);
         lcd.print(licznik);
    }
  
    if (digitalRead(10) == LOW) {
      licznik = 0.00;
          start = 1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RESET <- -> STOP");
    }
  }
 if (digitalRead(10) == LOW) {
      licznik = 0.00;
          start = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    -> START <- ");
    lcd.setCursor(5,1);
    lcd.print(licznik);
    delay(50);
    }
  

}
