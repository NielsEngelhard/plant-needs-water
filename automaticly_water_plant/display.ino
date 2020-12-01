/*
 * HARDWARE
 * Seven Segment Display
 * 
 * Used for displaying the "moist value".
 * 
 * I used a seven segment display, which can only represent one number. Another display can be used to
 * provide a more accurate vision of the "moist value".
 *
 * Display (left) to arduino (right):
 * TO DO
 */

 const int lowestPossibleSensorRead = 0;
 const int highestPossibleSensorRead = 100;
 const int highestNumberThatCanBeDisplayed = 9;
 const int lowestNumberThatCanBeDisplayed = 0;
 boolean valueMappedCorrectly = true;
 

 void displayMoistureValue(int value) {
  int displayableValue = mapValue(value);

  if (valueMappedCorrectly == true) {  // status LED for mapping value
    // display GREEN
  } else {
    // display RED
  }

  setValueToDisplay(displayableValue);
  
 }

/*
 * The value that is read can be between -100 and 100. When the value is minus, the sensor is not in the ground.
 * The value will be mapped to a value between 1 and 9. 10 becomes 1, 20 becomes 2 etc.
 */
 int mapValue(int value) {
    if (value < lowestPossibleSensorRead || value > highestPossibleSensorRead) { // the value is "not correct", when the sensor is out of the ground for example.
      valueMappedCorrectly = false;
      return 0;
    }

    int mapped_value = map(value, lowestPossibleSensorRead, highestPossibleSensorRead, lowestNumberThatCanBeDisplayed, highestNumberThatCanBeDisplayed);
    valueMappedCorrectly = true;
    return mapped_value;
 }

 void setValueToDisplay(int valueToDisplay) {
  // TO DO print number to display
 }
