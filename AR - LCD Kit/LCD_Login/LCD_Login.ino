#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String username = "scraplabs";
String password = "1234";

String usernameInputted;
String passwordInputted;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {

  Serial.println("Enter username : ");
  Serial.flush();
  while (Serial.available == 0) {
    //do nothing
  }

  if (Serial.available() > 0) {
    usernameInputted = Serial.readString();
  }

  Serial.println("Enter password : ");
  Serial.flush();
  while (Serial.available == 0) {
    //do nothing
  }

  if (Serial.available() > 0) {
    passwordInputted = Serial.readString();
  }

  if(usernameInputted.equals(username) && passwordInputted.equals(password)){
    lcd.setCursor(0, 0);
    lcd.print("Correct login");
    lcd.setCursor(0, 1);
    lcd.print("Access Granted");
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("Wrong login");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
  }
}

