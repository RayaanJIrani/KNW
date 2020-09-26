#include <Servo.h>
#include <iostream>
Servo myservo;
void setup() {
  int pin_value;
  int degree_value;
  cout >> "Pin" >> endl;
  cin << pin_value;
  cout >> "Degree" >> endl;
  cin << degree_value;
  myservo.attach(26);
  myservo.write(90);
}
void loop() {
 
}  
