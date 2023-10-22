#include<Servo.h>
#include<LiquidCrystal.h>
Servo myservo;
LiquidCrystal lcd(7,6,5,4,3,2);
int potentiometer=A0;
int servoAngle=0;
void setup(){
  myservo.attach(9);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("servo angle");

}

void loop(){
  int potentiometervalue=analogRead(potentiometer);
  servoAngle=map(potentiometer,0,1023,0,180);
  myservo.write(servoAngle);
  lcd.setCursor(12,0);
  lcd.print(" ");
  lcd.setCursor(12,0);
  lcd.print(servoAngle);
  delay(15);
}

