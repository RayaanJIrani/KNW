#include <Servo.h>
#include <conductivity.h>
#include <Sleep_n0m1.h>
#define Salinity1 A2;
#define Salinity2 A3;
#define Photo A5; // Sets the input sensor for the photoresistor as analog 5 (do not change)
#define Solar A6;
Servo rot_servo; // Arduinio IO port hook up 
Servo log_servo; 
Sleep sleep;

void move_continious_motor (int degrees = 0, int pin = 9); // Function moves the location n degrees counterclockwise
double read_photoresistor(); // Function reads the change in resistance caused by the presence of light
double read_solar();
void read_salinity();
int myCalibrationFunction(int raw);




void setup() {
  Serial.begin(9600); // This starts the Serial port allowing Octopus have a IO stream with laptop.
  int rot_pin_value = 9;
  int log_pin_value = 10; // pin changed from 11 to 10 to reflect change in hardware port usage.
  int rot_degree_value = 31;
  int log_degree_value = 100;
  sleep.pwrDownMode();
  move_continious_motor(rot_degree_value, rot_pin_value);
  move_analog_motor(log_degree_value, log_pin_value);
}

void loop() {
 
 void sunlight_track();
  delay(2000);
 // Salinty 1 Method
  delay(2000);
 //Salinty 2 Method
  delay(2000);
 sleep.sleepDelay(900000); //waits 15 minutes
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
  
  double read_photoresitor(){
    double light_level = analogRead(A5);
    double voltage = light_level * (5/1024); // converts analog to voltage
    Serial.print(voltage);
    Serial.print("\n");
    return light_level;
 }
double read_solar(){
    double solar = analogRead(A6);
    double voltage = solar * (5/1024); // converts analog to voltage
    Serial.print(solar);
    Serial.print("\n");
    return solar;
 }

 void read_salinity(){
  int conductivityReading = getConductivity();
  int salinity = myCalibrationFunction(conductivityReading);
  Serial.println("Salinity Reading:");
  Serial.println(salinity);
 
 }

 int myCalibrationFunction(int raw){
    return raw; // holder 
   
 }

 void sunlight_track(){
  double maxVoltage;
  for(int i = 0; i <= 180 ; i+=5){
    move_analog_motor(i, 10);
    delay(5000);
    double compareVoltage = read_photoresitor();
    
    if (compareVoltage > maxVoltage){
      maxVoltage = compareVoltage;
      }
    else{
     break;
      }  
    }
  }
