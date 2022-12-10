#include "flywheel.hpp";
#include "motors.hpp";

void flywheelVoltage(int speed1){
    speed1 = speed1*20;
    flywheel.move_voltage(speed1);
}
void toggleFlywheel(){
  if(flywheelstate == true){
    flywheelVoltage(600);
  }
  else{
    flywheel.move_brake();
  }
  flyWheelState = !flyWheelState;
}