const int pirPin = 12;
const int ledPin = 13;
const int buzzerPin = 11;

unsigned long previousMillis = 0;
const long interval = 400;
int buzz = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);
  Serial.println("Hello");
}

int prev_state = -1;
int cut_counter = 1;

void loop() {
  int state = digitalRead(pirPin);
  Serial.println(state);

  if (state == 1) {
    digitalWrite(ledPin, LOW);
    prev_state = 1;
    cut_counter = 1;
  } else {
    if (prev_state == 1 && cut_counter <= 3 && digitalRead(pirPin) == 0) {

      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        if (buzz <= 6) {
          if (digitalRead(buzzerPin) == LOW) {
            digitalWrite(buzzerPin, HIGH);
          } else {
            digitalWrite(buzzerPin, LOW);
          }
          buzz++;
        } else {
          cut_counter++;
          digitalWrite(buzzerPin, LOW);
          buzz = 0;
        }
      }
      // cut_counter++;
    } else {
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, LOW);
    }
  }
}
