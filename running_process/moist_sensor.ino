/*
 * HARDWARE
 * Moisture sensor is connected via a LM393 chip to the arduino.
 *
 * LM393 chip (left) to arduino (right):
 * AO  -> A0
 * DO  -> not connected
 * GND -> GRND
 * VCC -> 3.3V
 */
 
const int sensor_pin = A0;
int sensor_pin_read;
int mapped_sensor_pin_read;

int getMoistSensorValue() {
   sensor_pin_read = analogRead(sensor_pin);
   mapped_sensor_pin_read = map(sensor_pin_read,550,0,0,100);

   return mapped_sensor_pin_read;
}

void printMoistureValue() {
  int value = getMoistSensorValue();
  Serial.print("Mositure : ");
  Serial.print(value);
  Serial.print("%");
}

void moist_sensore_setup() {
  // initialize for printing.
  Serial.begin(9600);
  Serial.print("I am moister than moist");
}
