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

   // for a more accurate measurement/mapping, +1 is added.
   // (55 will be mapped to 5, instead of 4 etc.
   if (mapped_sensor_pin_read >= 9) {
    return mapped_sensor_pin_read;
   } else {
    return mapped_sensor_pin_read + 1;
   }
}

void moist_sensore_setup() {
  Serial.begin(9600);
}
