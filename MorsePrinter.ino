int lightPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String input = Serial.readString();
    String morse = filterMorse(input);
    showMorse(morse);
  }
}

String filterMorse(String input) {
  int inputLength = input.length();
  String outputString = "";

  for (int i = 0; i < inputLength; i++) {
    char c = input[i];
    if (c == '-' || c == '.') {
      outputString += c;
    }
  }

  return outputString;
}

void showMorse(String morse) {
  int morseLength = morse.length();

  for (int i = 0; i < morseLength; i++) {
    char c = morse[i];

    digitalWrite(lightPin, HIGH);

    if (c == '-') {
      //show long dah
      delay(650);
    } else {
      delay(250);
    }
    
    digitalWrite(lightPin, LOW);
    delay(200);
  }
}
