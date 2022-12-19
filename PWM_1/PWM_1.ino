#define diodaPIN 3

int wypelnienie =0;
int zmiana =5;

void setup() {
  pinMode(diodaPIN, OUTPUT);
}

void loop() {
  analogWrite(diodaPIN, wypelnienie);

  if (wypelnienie < 255) {
    wypelnienie = wypelnienie + zmiana;
  } else {
    wypelnienie = 0;
  }
delay(50);
}
