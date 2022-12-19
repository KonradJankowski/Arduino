#include <LiquidCrystal.h> //Dołączenie biblioteki
LiquidCrystal lcd(2,3,4,5,6,7); //Informacja o podłączeniu nowego wyświetlacza


void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0,0); //Ustawienie kursora
  lcd.print("Konrad Jankowski");
  lcd.setCursor(0,1); //Ustawienie Kursora
  lcd.print("www.intel.com"); //Wyświetlanie tekstu
  lcd.blink();


}

void loop() {
  lcd.noDisplay(); //Wyłącz i poczekaj
  delay (2000);
  lcd.display(); //Włącz i poczekaj
  delay(2000);
  
}
