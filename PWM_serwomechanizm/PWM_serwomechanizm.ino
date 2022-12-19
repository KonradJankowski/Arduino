#include <Servo.h>

Servo serwomechanizm; //Tworzę obiekt
int pozycja =0;
int zmiana =6;

void setup() {
  serwomechanizm.attach(3);

}

void loop() {
  if (pozycja < 180) { //
  //  serwomechanizm.write(pozycja);
  } else { 
    pozycja =0;
  }
 pozycja = pozycja + zmiana;
 delay(200);
}
