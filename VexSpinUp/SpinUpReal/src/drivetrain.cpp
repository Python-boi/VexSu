#include "main.h"
#include "drivetrain.hpp"
#include "motors.hpp"
#include "misc.hpp"


int speedLeft;
int speedRight;
void right_velocity(int speed6){
    speed6 = speed6*20;
    RFT.move_voltage(speed6);
    RF.move_voltage(speed6);
    RB.move_voltage(speed6);
}

void left_velocity(int speed){
    speed = speed * 20;
    LFT.move_voltage(speed);     
    LF.move_voltage(speed);
    LB.move_voltage(speed);
}

void brakes_left(){
     LFT.brake();
     LF.brake();
     LB.brake();
}
void brakes_right(){
     RFT.brake();
     RF.brake();
     RB.brake();
}
void drivetrainOpcontrol(){
  int leftMotorSpeed = master.get_analog(ANALOG_LEFT_Y);
int rightMotorSpeed = master.get_analog(ANALOG_RIGHT_Y);
int deadband = 5;
    	  if (abs(leftMotorSpeed) > deadband){
		speedLeft = leftMotorSpeed*3;
		
	  }
	      else{
		brakes_left();
	  }
	  if (abs(rightMotorSpeed) > deadband){
		speedRight = rightMotorSpeed*3;
		
	  }
	  else{
		brakes_right();
	  }
    left_velocity(speedLeft);
    right_velocity(speedRight);
}

void Drive(double distance){
  double driveSpeed = PIDcalculate(distance, (LF.get_position() +LFT.get_position()+LB.get_position()+RFT.get_position()+RF.get_position()+RB.get_position())/6 );
   right_velocity(driveSpeed);
   left_velocity(driveSpeed);
}

void Turn(double degrees, bool direction){
  if ((direction = 1)){
  double driveSpeed = PIDcalculate(degrees, (LF.get_position() +LFT.get_position()+LB.get_position()+RFT.get_position()+RF.get_position()+RB.get_position())/6 );
   right_velocity(driveSpeed);
   left_velocity(-driveSpeed);
  }

  if ((direction = 0)){
      double driveSpeed = PIDcalculate(degrees, (LF.get_position() +LFT.get_position()+LB.get_position()+RFT.get_position()+RF.get_position()+RB.get_position())/6 );
   right_velocity(-driveSpeed);
   left_velocity(driveSpeed);
  }
}