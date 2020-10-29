#include <Servo.h>
#include <conductivity.h>
#include <KNWRobot.h>
#define Salinity1 A2;
#define Salinity2 A3;
#define Photo A5; // Sets the input sensor for the photoresistor as analog 5 (do not change)
#define Solar A6;
Servo rot_servo; // Arduinio IO port hook up 
Servo log_servo; 

KNWRobot *myRobot;
void setup() {
  myRobot = new KNWRobot();
  Serial.begin(9600); // This starts the Serial port allowing Octopus have a IO stream with laptop.
  test_long();
  

}

void loop() {
}  

void run_russia(){
  move_analog_motor(120,10);
  read_salinity();
  delay(1000);
  
}
 
  void move_analog_motor(int degrees, int pin){
    log_servo.attach(pin);
    log_servo.write(degrees);
}
  
  double read_photoresitor(){
    double light_level = analogRead(A8);
    double voltage = light_level; // converts analog to voltage
    Serial.print(voltage);
    Serial.print("\n");
    return light_level;
 }
double read_solar(){
    double solar = analogRead(A6);
    double voltage = solar; // converts analog to voltage
    Serial.print(solar);
    Serial.print("\n");
    return solar;
 }

 

 void read_salinity(){
    int probeReading = getConductivity();
    Serial.println(myCalibrationFunction(probeReading));

 }

 double myCalibrationFunction(double raw){
    return raw;
 }
 void test(){
  int adc,i;
  double mean;
  adc = 0;
  delay(1000);
  for (i = 0; i < 5; ++i){
    adc += myRobot->getConductivity();
  }
  mean = ((double) adc)/5.0;
  myRobot->clearLine(1);
  Serial.println(mean);
 }
 void test_long(){
  move_analog_motor(100,10);
  test();
  test();
  test();
  move_analog_motor(0,10);
  delay(5000);
  move_analog_motor(100,10);
 }


  


 
