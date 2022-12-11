/*
  Simple Arduino project to demonstrate LED Fading using loop.

  Things Required:
    1. Arduino Uno
    2. Data Cable
    3. A jumper wire which connects pin 11 to pin 13

  Demo link: https://www.tinkercad.com/things/bEpjwN0QvYS
  (by Ddhruv Arora)
*/

int led = 11;           // the PWM pin

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {

  analogWrite(led, 0); // set brightness at 0
  delay(1000);

  for (int i = 0; i <= 1024; i++) {
    analogWrite(led, i); // update brightness with loop (i)
    delay(40);
  }
}
