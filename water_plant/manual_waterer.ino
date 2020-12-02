/*
 * LOGIC
 * for manually water the plant.
 */

// how long the water needs to flow when the button is pressed (seconds)
int pumpTime = 2; 

 // BEGIN import functions from other files (linking) */
int buttonPressed();
void pumpWater(int seconds);
void LEDBlueColor();
void LEDGreenColor();
// END   import functions from other files (linking) */

void giveWaterIfButtonPressed() {
  if (buttonPressed() == HIGH) { // button is pressed
    LEDBlueColor();
    pumpWater(pumpTime);
    LEDGreenColor();
  }
}
