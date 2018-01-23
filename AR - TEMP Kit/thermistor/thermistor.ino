#define pin A1

double val, vol, res, tem;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Thermistor Value : ");
  val = analogRead(pin);
  Serial.print(val);
  Serial.print(" | ");
  Serial.print("Thermistor Voltage : ");
  vol = 5 * val / 1024;
  Serial.print(vol);
  Serial.print(" Volts | ");
  Serial.print("Thermistor Resistance : ");
  res = 10000 * (5 - vol) / vol;
  Serial.print(res);
  Serial.print(" Ohms | ");
  Serial.print("Thermistor Temperature : ");
  tem = 25 + (1 / (-0.1167)) * (res / 10000 - 1);
  Serial.print(tem);
  Serial.print(" degree C");
  Serial.println();
}
