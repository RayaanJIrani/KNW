#include <Servo.h>
#define Photo A5; // Sets the input sensor for the photoresistor as analog 5 (do not change)
Servo myservo; // Arduinio IO port hook up 
void move_continious_motor (int degrees); // Function moves the location n degrees counterclockwise
double read_photoresistor(Photo name); // Function reads the change in resistance caused by the presence of light

void setup() {
  int pin_value = 9;
  int degree_value = 31;
  move_continious_motor(degree_value, pin_value);
}

void loop() {
 
}  

void move_continious_motor (int degrees = 0, int pin = 9){
  myservo.attach(pin);
  myservo.write(degrees); // This is a temporary call for the imported code to work 
  time_start = millis(); // Start time
  const double marginal_run_time = 0; // This is the amount of time longer which each marginal degree causes the program to run
  double end_time = marginal_run_time * degrees + time_start; // This calculates when the program should end 
  
  while (millis() <= end_time){ // If program should be running it will run
      myservo.write(180); //move servo as fast as possible
  }
  
  int read_photoresitor(Photo name){
    int light_level = analogRead(name);
    Serial.print(light_level);
    Serial.print("\n");
    return light_level;
  }
  
  
}
