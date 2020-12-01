/*
 * LOGIC
 * for automaticly water the plant when the soil is "dry".
 */

 // import function from water_pump file (linking) */
void pumpWater(int seconds);
int getMoistSensorValue();
void displayMoistureValue(int value);

 /*
 * WARNING
 * Each of the soil moist measurement sensor(s) are (a bit) different. The values they return may 
 * differ from the values that are used in this project. Good practice is to first check the 
 * measurements the sensor returns. Based on this measurement the variable "minMoistValue"
 * should be set to a - for your sensor/project - fitting value.
 */
 const int minMoistValue = 60;

 void waterPlant() {
 // timer based on "BlinkWithoutDelay" concept
 const long interval = 1000; // miliseconds
 unsigned long previousMillis = 0;
 unsigned long currentMillis = millis();
 int moistValue;

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    moistValue = getMoistSensorValue();
    
    // display 
    displayMoistureValue(moistValue);
    
    // water plant if neccesarry
    if (moistValue < minMoistValue) {
      pumpWater(4); // 4 seconds
    }
  }
 }


 
 
 
