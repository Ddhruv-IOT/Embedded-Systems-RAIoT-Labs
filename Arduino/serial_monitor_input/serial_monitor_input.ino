/*
  Simple Arduino project to demonstrate Serial Output on Serial Monitor.

  Things Required:
    1. Arduino Uno
    2. Data Cable

  Demo link: https://www.tinkercad.com/things/airhzrE3pxt
  (by Ddhruv Arora)
*/

String input; // Var to the input recieved from Serial Input (Monitor)

void setup() {
  Serial.begin(9600); // initialize the serial communication at 9600 baud rate

}

void loop() {
  while (Serial.available()) // check if serial is available (or not busy) for communication.
  {
    input = Serial.readString(); // read the input from Serial Monitor
    Serial.println(input); // Write the input on Serial Monitor
  }
  delay(100); // Add a delay to avoid Serial buffer
}
