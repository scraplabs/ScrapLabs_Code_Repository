#define lsensor A0
#define csensor A1
#define rsensor A2

#define lmotordir 2
#define lmotorspeed 3
#define rmotordir 4
#define rmotorspeed 5

#define buzz 13

int lw, lb, lm, rw, rb, rm, cw, cb, cm, l, r, c;

void setup() {
  // put your setup code here, to run once:
  pinMode(lsensor, INPUT);
  pinMode(csensor, INPUT);
  pinMode(rsensor, INPUT);

  pinMode(lmotordir, OUTPUT);
  pinMode(lmotorspeed, OUTPUT);
  pinMode(rmotordir, OUTPUT);
  pinMode(rmotorspeed, OUTPUT);

  lb = analogRead(lsensor);
  cb = analogRead(csensor);
  rb = analogRead(rsensor);

  digitalWrite(buzz, HIGH);
  delay(1000);
  digitalWrite(buzz, LOW);

  delay(5000);

  lw = analogRead(lsensor);
  cw = analogRead(csensor);
  rw = analogRead(rsensor);

  digitalWrite(buzz, HIGH);
  delay(1000);
  digitalWrite(buzz, LOW);

  lm = (lb + lw) / 2;
  cm = (cb + cw) / 2;
  rm = (rb + rw) / 2;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  l = analogRead(lsensor);
  c = analogRead(csensor);
  r = analogRead(rsensor);

  Serial.print(l);
  Serial.print(" ");
  Serial.print(c);
  Serial.print(" ");
  Serial.print(r);
  Serial.println();

  if (l < lm && c > cm && r < rm) {

    //straight

    digitalWrite(lmotordir, LOW);
    analogWrite(lmotorspeed, 200);
    digitalWrite(rmotordir, LOW);
    analogWrite(rmotorspeed, 200);
    digitalWrite(buzz, LOW);
  }

  else if (l > lm && c < cm && r < rm) {

    //left

    digitalWrite(lmotordir, LOW);
    analogWrite(lmotorspeed, 0);
    digitalWrite(rmotordir, LOW);
    analogWrite(rmotorspeed, 200);
    digitalWrite(buzz, LOW);
  }

  else if (l < lm && c < cm && r > rm) {

    //right

    digitalWrite(lmotordir, LOW);
    analogWrite(lmotorspeed, 200);
    digitalWrite(rmotordir, LOW);
    analogWrite(rmotorspeed, 0);
    digitalWrite(buzz, LOW);
  }
  else {

    //nothing
  }
}
