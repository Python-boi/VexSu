#pragma once
#include "main.h"
#include "motors.hpp"

int leftMotorSpeed = master.get_analog(ANALOG_LEFT_Y);
int rightMotorSpeed = master.get_analog(ANALOG_Right_Y);
int deadband = 5;

class drivetrain{

public:

//basic commands for ease of use
void right_velocity(int speed);
void left_velocity(int speed);
void brakes_left();
void brakes_right();
//sets Opcontrol
void drivetrainOpcontrol();
};