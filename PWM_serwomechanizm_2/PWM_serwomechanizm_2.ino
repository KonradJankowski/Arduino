#include <Servo.h>

Servo serwomechanizm;
int pozycja =0;
int zmiana = 6;

void setup() {
  serwomechanizm.attach(3);
}

void loop() {
  serwomechanizm.write(2);
  delay(1000);
  serwomechanizm.write(45);
  delay(1000);
  serwomechanizm.write(90);
  delay(1000);
  serwomechanizm.write(178);
  delay(1000);

}
