#include <Servo.h>
#define Salinity1 A2;
#definie Salinity2 A3;
#define Photo A5; // Sets the input sensor for the photoresistor as analog 5 (do not change)
#define Solar A6;
Servo rot_servo; // Arduinio IO port hook up 
Servo log_servo; 


void move_continious_motor (int degrees = 0, int pin = 9); // Function moves the location n degrees counterclockwise
double read_photoresistor(); // Function reads the change in resistance caused by the presence of light



void setup() {
  Serial.begin(9600); // This starts the Serial port allowing Octopus have a IO stream with laptop.
  int rot_pin_value = 9;
  int log_pin_value = 10; // pin changed from 11 to 10 to reflect change in hardware port usage.
  int rot_degree_value = 31;
  int log_degree_value = 100;
  move_continious_motor(rot_degree_value, rot_pin_value);
  move_analog_motor(log_degree_value, log_pin_value);
}

void loop() {
 
}  

void move_continious_motor (int degrees, int pin){
  rot_servo.attach(pin);
  rot_servo.write(degrees); // This is a temporary call for the imported code to work 
  int time_start = millis(); // Start time
  const double marginal_run_time = 0; // This is the amount of time longer which each marginal degree causes the program to run
  double end_time = marginal_run_time * degrees + time_start; // This calculates when the program should end 
  
  while (millis() <= end_time){ // If program should be running it will run
      rot_servo.write(180); //move servo as fast as possible
  }
  
} 
  void move_analog_motor(int degrees, int pin){
    log_servo.attach(pin);
    log_servo.write(degrees);
}
  
  int read_photoresitor(){
    int light_level = analogRead(A5);
    Serial.print(light_level);
    Serial.print("\n");
    return light_level;
 }
   double read_solar(){
    double solar = analogRead(A6);
    Serial.print(solar);
    Serial.print("\n");
    return solar;
 }

 double read_salinity(){
  double salinity1 = analogRead(A2);
  double salinity2 = analogRead(A3);
  Serial.print(salinity1);
  Serial.print("\n");
  Serial.print(salinity2);
  Serial.print("\n");
 }
  


 
