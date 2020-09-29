#include <Servo.h>
//TODO add user inputs to select pin value.
Servo myservo;
void move_motor (int degrees); // Function moves the location n degrees counterclockwise
void setup() {
  int pin_value;
  int degree_value;
  pin_value = 9;
  degree_value = 31;
  myservo.attach(pin_value);
  move_motor(degree_value);
}
void loop() {
 
}  
void move_motor (int degrees){
   myservo.write(degrees); // This is a temporary call for the imported code to work 
  time_start = millis(); // Start time
  const double marginal_run_time = 0; // This is the amount of time longer which each marginal degree causes the program to run
  double end_time = marginal_run_time * degrees + time_start; // This calculates when the program should end 
  while (millis() <= end_time){ // If program should be running it will run
    myservo.write(180); //move servo as fast as possible
  }
  
}
