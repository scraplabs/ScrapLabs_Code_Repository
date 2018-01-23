#define pin A1
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

double val, vol, res, tem;

void setup() {
    lcd.begin(16, 2);

  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 0);
  Serial.print("Thermistor Value : ");
  val = analogRead(pin);
  Serial.print(val);
  Serial.print(" | ");
  Serial.print("Thermistor Voltage : ");
  vol = 5 * val / 1024;
  Serial.print(vol);
  Serial.print(" Volts | ");
  Serial.print("Thermistor Resistance : ");
  res = 1000 * (5 - vol) / vol;
  Serial.print(res);
  Serial.print(" Ohms | ");
  Serial.print("Thermistor Temperature : ");
  tem = 25 + (1 / (-0.1167)) * (res / 1000 - 1);
  Serial.print(tem);
  Serial.print(" degree C");
  Serial.println();
  lcd.print("temperatureis:");
   lcd.setCursor(0, 1 );
 
  lcd.print(tem);
}
