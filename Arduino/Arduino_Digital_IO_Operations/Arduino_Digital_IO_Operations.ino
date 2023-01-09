/*
  Simple Arduino project to demonstrate LED Blinking.
  Things Required:
    1. Arduino Uno
    2. Data Cable
  Demo link: https://www.tinkercad.com/things/3ZBEM6dunNY
  (by Ddhruv Arora)
*/

#define led 4
#define button 5

void setup() {
  Serial.begin(9600);

  pinMode( led, OUTPUT );
  pinMode( button, INPUT );
  pinMode( 6, INPUT );
  pinMode( 7, OUTPUT);

  Serial.println("Hello form MCU");
}

int buttonPushed = 0;
int switchOn = 0;

void loop() {
  if (digitalRead(button) == 1)
  {
    Serial.println("Button Pushed");
    digitalWrite(led, HIGH);
    delay(1000);
  }

  else {
    digitalWrite(led, LOW);
    delay(100);
  }

  switchOn = digitalRead(6);
  
  if (switchOn == 1) {
    Serial.println("The switch is ON");
    digitalWrite(7, HIGH);
    delay(100);
  }

  else {
    digitalWrite(7, LOW);
    delay(100);
  }
}
