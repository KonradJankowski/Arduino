/**

* PanTiltControl

*/


 #include <Servo.h>


 Servo horzServo; // Create a servo object for the pan (horizontal) servo

Servo vertServo; // Create a servo object for the tilt (vertical) servo


 const int ledPin = 13; // LED output pin

const int buttonPin = 2; //Input for joystick push button

int buttonState = 0;


 boolean lastButton = LOW;

boolean currentButton = LOW;

boolean ledOn = false;


 int horzPin = 0; // Analog input for the joystick horizontal axis

int vertPin = 1; // Analog input for the joystick vertical axis

int vertVal; // Value read from the vertical axis

int horzVal; // Value read from the horizontal axis


 /**

* Setup

*/

void setup()

{

  pinMode (ledPin, OUTPUT); // initialize pin as output

  pinMode (buttonPin, INPUT); // initialize pin as input  

  horzServo.attach(9); // Use pin 9 PWM output for horizontal servo

  vertServo.attach(10); // Use pin 10 PWM output for vertical servo

}

boolean debounce (boolean last)

{

  boolean current = digitalRead (buttonPin);

  if (last != current)

  {

    delay(5);

    current = digitalRead(buttonPin);

  }

  return current;

}


 /**

* Main program loop

*/

void loop()

{

  currentButton = debounce (lastButton);

  if (lastButton == LOW && currentButton == HIGH)

  {

    ledOn= !ledOn;

      }

      lastButton = currentButton;

    digitalWrite (ledPin, ledOn);




  horzVal = analogRead(horzPin); // Read joystick horizontal position

  horzVal = map(horzVal, 0, 1023, 0, 179); // Scale reading to suit servo

  horzServo.write(horzVal); // Move servo to required position


   vertVal = analogRead(vertPin); // Read joystick vertical position

  vertVal = map(vertVal, 0, 1023, 0, 179); // Scale reading to suit servo

  vertServo.write(vertVal); // Move servo to required position

  delay(15); // Give the servos time to settle

  




}
