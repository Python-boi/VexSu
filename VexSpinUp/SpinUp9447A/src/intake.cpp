#include "main.h"
#include "motors.hpp"
#include "intake.hpp"

void intakeVoltage(int speed4){
    speed4 = speed4*60;
    flywheel.move_voltage(speed4);
}
void intakeToggle(){
    if( dist.get() < fullmag){
       intakeVoltage(120);
    }
    else {
        intake.move_brake();
    }
}