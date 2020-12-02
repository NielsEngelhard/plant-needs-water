/*
 * Created by : Niels Engelhard
 * Github page: https://github.com/NielsEngelhard
 *
 * Last edit: 02-12-2020
 *
 */

/* BEGIN import setups from other "files" (linking) */
void moist_sensore_setup();
void water_pump_setup();
void LEDSetup();
void buttonSetup();
void displaySetup();

void waterPlantWhenNeeded();
void giveWaterIfButtonPressed();
/* END   import setups from other "files" (linking) */


/*
 * Contains all the setup's of all other .ino files.
 */
void setup() {
  moist_sensore_setup();
  water_pump_setup();
  LEDSetup();
  buttonSetup();
  displaySetup();
}


/*
 * The - two - running processes. The application has two things it can do. 
 * 1. Water the plant automatically based on the sensor's read -> waterPlantWhenNeeded().
 * 2. Water the plant manually based on a button click -> giveWaterIfButtonPressed().
 */
void loop() {
  waterPlantWhenNeeded();
  giveWaterIfButtonPressed();
}
