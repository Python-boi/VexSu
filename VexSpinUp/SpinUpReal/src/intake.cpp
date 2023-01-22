#include "main.h"
#include "motors.hpp"
#include "intake.hpp"
#include "pros/colors.h"
int speed4;
int fullmag;
int teamColor = COLOR_BLUE;
void intakeVoltage(int speed4){
    speed4 = speed4*60;
    intake.move_voltage(speed4);
}
void intakeToggle(){
    if( Dist.get() < fullmag){
       intakeVoltage(120);
    }
    else {
        intake.brake();
    }
}

void rollers(){
    if(Optic.get_proximity() < 5){
        if (Optic.get_hue() != teamColor){
            intakeVoltage(120);
        }
    }
}
void intakeOpControl(){
    intakeToggle();
    rollers();
}