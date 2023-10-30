/*
  Simple Arduino project to demonstrate distance calculation using Ultrasonic sensor.

  Things Required:
    1. Arduino Uno
    2. Data Cable
    3. Ultrasonic Sensor

    Echo pin     ------> Arduino pin 2
    Trigger pin  ------> Arduino pin 3
    VCC          ------> 5v
    GND          ------> GND

  Demo link: https://www.tinkercad.com/things/0GcFU7Y5cXk
  (by Ddhruv Arora)
*/


#define echoPin 2  // setting the echo pin 
#define trigPin 3  // setting the trigger pin

long duration;
int distance;

void setup() {

  Serial.begin(9600); // Start the serial communication
  pinMode(trigPin, OUTPUT); // trigger is used to generate pulse, hence output
  pinMode(echoPin, INPUT); // echo is used to recieve the pulse, hence input

}

void loop() {

  // pulse generation block.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Receving the pulse and calculating the distance
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2); /* d = speed x time, speed = 0.034 (for air) */

  // printing the distance on Serial Monitor
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm ");

  // It ensures no data buffer happens.
  delay(1000);

}
