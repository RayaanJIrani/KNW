#include <Servo.h>
//TODO add user inputs to select pin value.
Servo myservo;
void setup() {
  int pin_value;
  int degree_value;
  pin_value = 26;
  degree_value = 31;
  myservo.attach(pin_value);
  myservo.write(degree_value);
}
void loop() {
 
}  
