/* Treat-Machine
 *  Dog treat dispenser operated from push button
 *  Designed for James Dunn - REMAP Customer
 *  by
 *  Rupert Powell (REMAP)
 *  2017
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo


int load_pos = 49;    // Default = 50 variable to store the servo position for loading a treat
int dispense_pos = 20; // = Default 10 position to dispense the treat
const int buttonPin = 2;
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState == LOW) {
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    // Move to the dispense position
    digitalWrite(LED_BUILTIN, HIGH);
    myservo.write(dispense_pos);
    delay(1000);
     myservo.write(load_pos);
    delay(700);
    myservo.detach();  // attaches the servo on pin 9 to the servo objectq
    digitalWrite(LED_BUILTIN, LOW);
  }
}
