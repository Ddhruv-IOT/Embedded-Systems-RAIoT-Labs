/*
  Simple Arduino project to demonstrate Serial Output on Serial Monitor.

  Things Required:
    1. Arduino Uno
    2. Data Cable

  Demo link: https://www.tinkercad.com/things/95hGQzOk7e3
  (by Ddhruv Arora)
*/

void setup() {
  Serial.begin(9600); // initialize the serial communication at 9600 baud rate
  
}

void loop() {
  Serial.println("Hello World!!"); // Print your message on Serial Monitor
  delay(1000); // Wait for a second to avoid message spamming
}
