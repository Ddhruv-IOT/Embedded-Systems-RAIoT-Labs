/*
  Simple Arduino project to demonstrate LED Blinking.

  Things Required:
    1. Arduino Uno
    2. Data Cable

  Demo link: https://www.tinkercad.com/things/3ZBEM6dunNY
  (by Ddhruv Arora)
*/

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  // In place of LED_BUILTIN we can also write pin 13
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off
  delay(1000);                       // wait for a second

}
