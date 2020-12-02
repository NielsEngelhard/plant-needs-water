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
 * The wires of the seven segment display are connected each with a different port. For more info
 * see the setup in the bottom of this file.
 */

 void LEDRedColor();
 void LEDGreenColor();

 const int lowestPossibleSensorRead = 0;
 const int highestPossibleSensorRead = 100;
 const int highestNumberThatCanBeDisplayed = 9;
 const int lowestNumberThatCanBeDisplayed = 0;
 boolean valueMappedCorrectly = true;

/*
 * Displayable numbers put in one multidimensional array. The first value of the [this][] represents the number.
 * The second value [][this] represents the "LED" on the seven segment display that needs to be on (1) or off (0).
 * If you want for example the whole number of 5, you need to read all 8 variables of [5][i].
 */
 int displayableNumbers[10][8] = {{1, 1, 1, 0, 1, 1, 1, 1}, // 0
                                 {1, 0, 0, 0, 1, 1, 0, 0},  // 1
                                 {1, 1, 0, 1, 0, 1, 1, 1},  // 2
                                 {1, 1, 0, 1, 1, 1, 1, 0},  // 3
                                 {1, 0, 1, 1, 1, 1, 0, 0},  // 4
                                 {0, 1, 1, 1, 1, 1, 1, 0},  // 5
                                 {0, 1, 1, 1, 1, 1, 1, 1},  // 6
                                 {1, 1, 0, 0, 1, 1, 0, 0},  // 7
                                 {1, 1, 1, 1, 1, 1, 1, 1},  // 8
                                 {1, 1, 1, 1, 1, 1, 1, 0}   // 9
                                 };
 

 void displayMoistValue(int value) {
  int displayableValue = mapValue(value);

  if (valueMappedCorrectly == true) {  // status LED for mapping value
    LEDGreenColor();
  } else {
    LEDRedColor();
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

 void setValueToDisplay(int value) {
  for (int i = 0; i < 8; i++) {
    if (displayableNumbers[value][i] == 1) {
      if (i == 0) {
        digitalWrite(13, HIGH);
      } else {
        digitalWrite(i + 1, HIGH);
      }
    } else {
      if (i == 0) {
        digitalWrite(13, LOW);
      } else {
        digitalWrite(i + 1, LOW);
      }
    }
  }
}

void displaySetup() {
  pinMode(13, OUTPUT);// right up
  pinMode(2, OUTPUT); // mid up
  pinMode(3, OUTPUT); // left up
  pinMode(4, OUTPUT); // mid mid 
  pinMode(5, OUTPUT); // right under
  pinMode(6, OUTPUT); // dot
  pinMode(7, OUTPUT); // mid under
  pinMode(8, OUTPUT); // left under
}
