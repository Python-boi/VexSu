#pragma once
#include "main.h"
#include "motors.hpp"
bool flyWheelState = false;
class flywheel{
public:
void flywheelVoltage(int speed1);

void toggleFlywheel();

bool getFlywheelState();

void flywheelOpcontrol();
};

