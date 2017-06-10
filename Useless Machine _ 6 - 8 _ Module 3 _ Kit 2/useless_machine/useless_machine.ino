#define switchPin 10
#define motordir 2
#define motorspeed 3

//defining sum to use later
int sum;

bool switchState = false;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(motordir, OUTPUT);
  pinMode(motorspeed, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  sum = 0;
  
  Serial.print(digitalRead(switchPin) + " : ");
  if (digitalRead(switchPin) == 1) {
  
    //debouncing code
    for (int i = 0; i < 40; i++)
    {
      Serial.print(digitalRead(switchPin) + " ");
      sum += digitalRead(switchPin);
      delay(10);
    }
    sum = sum / 40;
    Serial.println("Final result after debouncing : " + sum);
    Serial.println();
  }
  if (sum == 1) {
    switchState = true;
  }
  else {
    switchState = false;
  }

  if (switchState == true) {
    digitalWrite(motordir, LOW);
    analogWrite(motorspeed, 200);
    delay(200);
    digitalWrite(motordir, HIGH);
    analogWrite(motorspeed, 200);
    delay(300);
    digitalWrite(motordir, LOW);
    analogWrite(motorspeed, 0);
    switchState = false;
  }
  else {

  }
}

