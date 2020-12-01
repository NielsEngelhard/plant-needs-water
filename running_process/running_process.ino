/*
 * Created by : Niels Engelhard
 * Github page: https://github.com/NielsEngelhard
 * 
 * STILL WORK IN PROGRESS
 * 
 * Last edited: 01-12-2020
 *
 */

/* BEGIN import setups from other "files" (linking) */
void moist_sensore_setup();
void water_pump_setup();
void turnPumpOnAndOff();

void printMoistureValue();
/* END   import setups from other "files" (linking) */


void setup() {
  moist_sensore_setup();
  water_pump_setup();
}

// the loop function runs over and over again forever
void loop() {
  printMoistureValue();
  delay(3000);
}
