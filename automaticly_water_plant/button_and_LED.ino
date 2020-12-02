/*
 * HARDWARE
 * Standard arduino button
 *
 * Button (left) to arduino (right):
 * 5V  -> 5V
 * GND -> GND
 * Com -> 12
 */
 
const int buttonPin = 12;
int buttonState = 0; 

void buttonSetup() {
  pinMode(buttonPin, INPUT);
}

int buttonPressed() {
  buttonState = digitalRead(buttonPin);
  return buttonState;
}

 /*
 * HARDWARE
 * RGB LED light (standard arduino)
 *
 * RGB light (left) to arduino (right):
 * RED   -> ~11 arduino PWM slot
 * GND   ->  GND
 * GREEN -> ~10 arduino PWM slot
 * BLUE  -> ~9  arduino PWM slot
 */

const int redPin= 11;
const int greenPin = 10;
const int bluePin = 9;

void LEDSetup() {
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}

void LEDRedColor() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void LEDGreenColor() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
}

void LEDBlueColor() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}

void LEDPinkColor() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 192);
  analogWrite(bluePin, 203);
}

void LEDNoColor() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}
