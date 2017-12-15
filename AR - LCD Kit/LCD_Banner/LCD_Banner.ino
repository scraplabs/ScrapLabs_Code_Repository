#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

char messageOnLCD[16];

String message = "Welcome to the exciting world of ScrapLabs!";

message.concat(" ");

void loop() {

  int lengthOfMessage = message.length();

  for (int i = 0; i < lengthOfMessage - 16; i++) {
    for (int j = 0; j < 16; j++) {
      messageOnLCD[j] = message.charAt(j+i);
    }
    lcd.setCursor(0,0);
    lcd.print(messageOnLCD);
    delay(100);
  }
}
