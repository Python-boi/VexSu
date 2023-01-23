#pragma once
#include "main.h"
#include "motors.hpp"


//basic commands for ease of use
void right_velocity(int speed);
void left_velocity(int speed);
void brakes_left();
void brakes_right();
//sets Opcontrol
void drivetrainOpcontrol();

void Drive(double distance);