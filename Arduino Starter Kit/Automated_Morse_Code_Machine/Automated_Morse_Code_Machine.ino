#define ledPin 13
#define buzzPin 12

String message;
char alphabet;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    message = Serial.readString();
  }

  message.toLowerCase();

  Serial.println();
  Serial.println(message);
  Serial.println();

  for (int i = 0; i < message.length(); i++) {
    alphabet = message[i];

    Serial.println();
    Serial.print(alphabet);
    Serial.println();

    if (alphabet == ' ') {

      wordend();
    }
    else if (alphabet == 'a') {

      dit();
      dah();
    }
    else if (alphabet == 'b') {

      dah();
      dit();
      dit();
      dit();
    }
    else if (alphabet == 'c') {
      dah();
      dit();
      dah();
      dit();
    }
    else if (alphabet == 'd') {

      dah();
      dit();
      dit();
    }
    else if (alphabet == 'e') {

      dit();
    }
    else if (alphabet == 'f') {

      dit();
      dit();
      dah();
      dit();
    }
    else if (alphabet == 'g') {

      dah();
      dah();
      dit();
    }
    else if (alphabet == 'h') {

      dit();
      dit();
      dit();
      dit();
    }
    else if (alphabet == 'i') {

      dit();
      dit();
    }
    else if (alphabet == 'j') {

      dit();
      dah();
      dah();
      dah();
    }
    else if (alphabet == 'k') {

      dah();
      dit();
      dah();
    }
    else if (alphabet == 'l') {

      dit();
      dah();
      dit();
      dit();
    }
    else if (alphabet == 'm') {

      dah();
      dah();
    }
    else if (alphabet == 'n') {

      dah();
      dit();
    }
    else if (alphabet == 'o') {

      dah();
      dah();
      dah();
    }
    else if (alphabet == 'p') {

      dit();
      dah();
      dah();
      dit();
    }
    else if (alphabet == 'q') {

      dah();
      dah();
      dit();
      dah();
    }
    else if (alphabet == 'r') {

      dit();
      dah();
      dit();
    }
    else if (alphabet == 's') {

      dit();
      dit();
      dit();
    }
    else if (alphabet == 't') {

      dah();
    }
    else if (alphabet == 'u') {

      dit();
      dit();
      dah();
    }
    else if (alphabet == 'v') {

      dit();
      dit();
      dit();
      dah();
    }
    else if (alphabet == 'w') {

      dit();
      dah();
      dah();
    }
    else if (alphabet == 'x') {

      dah();
      dit();
      dit();
      dah();
    }
    else if (alphabet == 'y') {

      dah();
      dit();
      dah();
      dah();
    }
    else if (alphabet == 'z') {

      dah();
      dah();
      dit();
      dit();
    }
    else if (alphabet == '1') {

      dit();
      dah();
      dah();
      dah();
      dah();
    }
    else if (alphabet == '2') {

      dit();
      dit();
      dah();
      dah();
      dah();
    }
    else if (alphabet == '3') {

      dit();
      dit();
      dit();
      dah();
      dah();
    }
     else if (alphabet == '4') {

      dit();
      dit();
      dit();
      dit();
      dah();
    }
     else if (alphabet == '5') {

      dit();
      dit();
      dit();
      dit();
      dit();
    }
    else if (alphabet == '6') {

      dah();
      dit();
      dit();
      dit();
      dit();
    }
    else if (alphabet == '7') {

      dah();
      dah();
      dit();
      dit();
      dit();
    }
    else if (alphabet == '8') {

      dah();
      dah();
      dah();
      dit();
      dit();
    }
    else if (alphabet == '9') {

      dah();
      dah();
      dah();
      dah();
      dit();
    }
    else if (alphabet == '0') {

      dah();
      dah();
      dah();
      dah();
      dah();
    }

    alphabetend();
    alphabet = '.';
  }

  message = "";
}

void on() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzPin, HIGH);
}

void off() {
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzPin, LOW);
}

void dit() {
  on();
  delay(100);
  off();
  delay(100);
}

void dah() {
  on();
  delay(300);
  off();
  delay(100);
}

void alphabetend() {
  delay(200);
}

void wordend() {
  delay(400);
}
