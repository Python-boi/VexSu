#include "main.h"
#include "flywheel.hpp"
#include "motors.hpp"

bool flyWheelState = false;
bool state = false;

void flywheelVoltage(int speed1){
    speed1 = speed1*20;
    flywheel.move_voltage(speed1);
}
void toggleFlywheel(){
  flyWheelState = !flyWheelState;
  if(flyWheelState == true){
    flywheelVoltage(600);
  }
  else{
    flywheel.brake();
  }
  
}
void flywheelOpcontrol(){
  if(master.get_digital_new_press(DIGITAL_R1)){
		toggleFlywheel();
	   }
	   

   if(master.get_digital_new_press(DIGITAL_L1)){
    loader.set_value(!state);
    state = true;
    pros::delay(10);
    loader.set_value(!state);
    state=false;
    pros::delay(10);
   }
}