/*
 * HARDWARE
 * Water pump is connected via a low level trigger to the arduino.
 * I used a Micro Submersible Motor Water Pump (3-6V), which needed to be connected to a external power source.
 *
 * low level trigger (left) to arduino (right):
 * VCC -> 5V
 * GND -> GRND
 * IN  -> A5
 */

const int RELAY_PIN = A5;

void water_pump_setup() {
  // initialize digital pin <RELAY_PIN> as an output.
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(A5, HIGH);
}

void pumpWater(int seconds) {
  digitalWrite(RELAY_PIN, LOW); // turn on pump
  delay(seconds * 1000);         // TO DO :: replace delay  
  digitalWrite(RELAY_PIN, HIGH);  // turn off pump
}
