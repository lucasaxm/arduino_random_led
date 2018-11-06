/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int redLedPin =  12;      // the number of the LED pin
const int greenLedPin =  4;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
long randNumber;
int i;
int chosenPin;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  randomSeed(analogRead(0));
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.print("RED LED PIN: ");
  Serial.print(digitalRead(redLedPin));
  Serial.print(" | GREEN LED PIN: ");
  Serial.print(digitalRead(greenLedPin));
  Serial.print(" | BUTTON PIN: ");
  Serial.println(buttonState);
  // check if the pushbutton is pressed. If it is, the buttonState is LOW:
  if (buttonState == LOW) {
    chosenPin = random(2) ? greenLedPin : redLedPin;
    for (i=0; i<25; i++){
      delay(i*10);
      if (i%2) {
        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
      }
      else {
        digitalWrite(greenLedPin, HIGH);
        digitalWrite(redLedPin, LOW);
      }
    }
    if (chosenPin == greenLedPin) {
        if (digitalRead(greenLedPin) == HIGH){
          delay(i*20);
          digitalWrite(greenLedPin, LOW);
          digitalWrite(redLedPin, HIGH);
        }
        delay(i*20);
        digitalWrite(greenLedPin, HIGH);
        digitalWrite(redLedPin, LOW);
    } else if (chosenPin == redLedPin) {
        if (digitalRead(redLedPin) == HIGH){
          delay(i*20);
          digitalWrite(greenLedPin, HIGH);
          digitalWrite(redLedPin, LOW);
        }
        delay(i*20);
        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
    }
    
    delay(3000);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
}
