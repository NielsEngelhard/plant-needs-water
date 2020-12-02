/*
 * LOGIC
 * for automaticly water the plant when the soil is "dry".
 */

// BEGIN import functions from other files (linking) */
void pumpWater(int seconds);
int getMoistSensorValue();
void displayMoistValue(int value);
void LEDBlueColor();
void LEDPinkColor();
// END   import functions from other files (linking) */

 /*
 * WARNING
 * Each of the soil moist measurement sensor(s) are (a bit) different. The values they return may 
 * differ from the values that are used in this project. Good practice is to first check the 
 * measurements the sensor returns. Based on this measurement the variable "minMoistValue"
 * should be set to a - for your sensor/project - fitting value.
 */
 const int minMoistValue = 25;

 /*
 * SAFETY CHECK
 * This boolean value will be put to true if the plant is "just watered". If the check after the "water" 
 * also results in watering, the system will be stopped and the LED will turn PINK. This is done to prevent
 * the plant from drowning.
 */
 boolean justWatered = false;
 boolean stopAutoWatering = false;

 void waterPlantWhenNeeded() {
  if (stopAutoWatering == false) {
   // timer based on "BlinkWithoutDelay" concept
   const long interval = 2000; // miliseconds (3600000 == one hour)
   unsigned long previousMillis = 0;
   unsigned long currentMillis = millis();
   int moistValue;
  
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      moistValue = getMoistSensorValue();
      
      // display 
      displayMoistValue(moistValue);
      
      // water plant if neccesarry
      if (moistValue < minMoistValue) {
        if (justWatered == true) { // stop the app, if the plant was already watered.
          LEDPinkColor();
          stopAutoWatering = true;
        } else {
          LEDBlueColor();
          pumpWater(4); // 4 seconds
          justWatered = true;
        }
      } else {
        justWatered = false;
      }
    }
  }
 }


 
 
 
