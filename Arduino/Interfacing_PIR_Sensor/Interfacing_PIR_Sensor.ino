/*
  Interfacing PIR sensor with Arduino.
  
  Things Required:
    1. Arduino Uno
    2. Data Cable
    3. PIR Motion Sensor 
    4. RGB Led 
    5. 1k OHM resistor

  Connections: 
   PIR VCC -----> Arduino VCC
   PIR GND -----> Arduino GND
   PIR SGN -----> Arduino PIN 7 

   RGB RED -----> Arduino PIN 13
   RGB BLU -----> Arduino PIN 12
   RGB GRN -----> Arduino PIN 11
   RGB GND -----> Arduino GND
   
  Demo link: https://www.tinkercad.com/things/0n63d3Rt4Mf
  (by Ddhruv Arora)
*/

#define red 13
#define blue 12
#define green 11
#define pir 7

void setup() {
  Serial.begin(9600);

  pinMode(pir, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);

  Serial.println("Security System ON");
}

int pirVal = 0;

void loop() {

  pirVal = digitalRead(pir);
  Serial.println(pirVal);

  if (pirVal == 1) {
    digitalWrite(green, LOW);
    Serial.println("Someone Detected");

    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(blue, LOW);
    delay(500);
    digitalWrite(red, LOW);
    delay(500);
    digitalWrite(blue, HIGH);
    delay(500);
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(blue, LOW);
    delay(1000);
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(blue, LOW);
    delay(500);
    digitalWrite(red, LOW);
    delay(500);
    digitalWrite(blue, HIGH);
    delay(500);
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(blue, LOW);
  }


  else {
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    delay(10);
  }
}
