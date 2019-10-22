#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
Liq;;;uidCrystal lcd(13, 12, 11, 10, 9, 8); //lcd use 13~7
/*
 * R0S pin 13
 * E pin to pin 12
 * D4 pin to pin 11
 * D5 pin to pin 10
 * D6 pin to pin 9
 * D7 pin to pin 8
*/

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
