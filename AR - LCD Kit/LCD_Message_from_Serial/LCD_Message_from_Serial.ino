#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String message;
char messageOnLCD[16];

int lengthOfMessage;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  Serial.flush();

  while (Serial.available == 0) {
    //do nothing
  }

  if (Serial.available() > 0) {

    message = Serial.readString();
  }

  message.concat(" ");

  lengthOfMessage = message.length();
}

void loop() {
  
  lengthOfMessage = message.length();

  for (int i = 0; i < lengthOfMessage - 16; i++) {
    for (int j = 0; j < 16; j++) {
      messageOnLCD[j] = message.charAt(j + i);
    }
    lcd.setCursor(0, 0);
    lcd.print(messageOnLCD);
    delay(100);
  }
}

