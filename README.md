#include <WiFi.h>
#include <ESP32WebServer.h>
#include <BlynkSimpleEsp32.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

const char* authToken = "YOUR_AUTH_TOKEN";

ESP32WebServer server(80);

BlynkSimpleEsp32 blynk;

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristServo;
Servo wristRotateServo;
Servo gripperServo;

int basePos = 90;
int shoulderPos = 90;
int elbowPos = 90;
int wristPos = 90;
int wristRotatePos = 90;
int gripperPos = 90;

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  baseServo.attach(13);
  shoulderServo.attach(14);
  elbowServo.attach(15);
  wristServo.attach(16);
  wristRotateServo.attach(17);
  gripperServo.attach(18);

  blynk.begin(authToken);

  blynk.attachPin(V1, baseServo);
  blynk.attachPin(V2, shoulderServo);
  blynk.attachPin(V3, elbowServo);
  blynk.attachPin(V4, wristServo);
  blynk.attachPin(V5, wristRotateServo);
  blynk.attachPin(V6, gripperServo);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  basePos = value;
  baseServo.write(value);
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  shoulderPos = value;
  shoulderServo.write(value);
}

BLYNK_WRITE(V3) {
  int value = param.asInt();
  elbowPos = value;
  elbowServo.write(value);
}

BLYNK_WRITE(V4) {
  int value = param.asInt();
  wristPos = value;
  wristServo.write(value);
}

BLYNK_WRITE(V5) {
  int value = param.asInt();
  wristRotatePos = value;
  wristRotateServo.write(value);
}

BLYNK_WRITE(V6) {
  int value = param.asInt();
  gripperPos = value;
  gripperServo.write(value);
}

void loop() {
  blynk.run();
}
