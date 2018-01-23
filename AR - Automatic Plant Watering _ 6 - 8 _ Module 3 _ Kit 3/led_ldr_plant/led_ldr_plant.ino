
bool pumpstate = 1;
int plantpin, ldrpin;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);

}

void loop()
{
  plantpin = analogRead(A0);
  ldrpin = analogRead(A5);

  Serial.print("ldr :");
  Serial.print(ldrpin);
  Serial.print("|");
  Serial.println();

  Serial.print("plant :");
  Serial.print(plantpin);
  Serial.print("|");
  Serial.println();

  Serial.print("pump :");
  Serial.print(pumpstate);
  Serial.print("|");
  Serial.println();

  if (plantpin <= 30)
  {
    pumpstate = 0;
  }
  if (plantpin <= 50 && 3 < ldrpin && ldrpin < 35)
  {
    pumpstate = 0;    // if the plant is dry and light is optimum,switch on the pump
  }
  else if (plantpin >= 150 || ldrpin <= 3 || ldrpin > 35)
  {
    pumpstate = 1;  // if the plant is watered well enough or the light is not correct, switch off the pump
  }
  else
  {
    //do nothing
  }
  if (pumpstate == 0)
  {
    analogWrite(3, 255);  // to run the motor for 1 second
    delay(1000);
    analogWrite(3, 0);  // to stop the motor for 10 seconds
    delay(10000);
  }

  for (int i = 4; i <= 13; i++)
  {

    digitalWrite(i, LOW);  //to asssign the pins for the LEDs
  }

  if (plantpin >= 150)
    digitalWrite(4, HIGH);

  if (plantpin >= 139)
    digitalWrite(5, HIGH);

  if (plantpin >= 128)
    digitalWrite(6, HIGH);

  if (plantpin >= 117)
    digitalWrite(7, HIGH);

  if (plantpin >= 106)
    digitalWrite(8, HIGH);

  if (plantpin >= 95)
    digitalWrite(9, HIGH);

  if (plantpin >= 84)
    digitalWrite(10, HIGH);

  if (plantpin >= 73)
    digitalWrite(11, HIGH);

  if (plantpin >= 62)
    digitalWrite(12, HIGH);

  if (plantpin >= 51)
    digitalWrite(13, HIGH);
  else
  {
    // do nothing
  }

}
