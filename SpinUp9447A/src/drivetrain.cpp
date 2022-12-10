#include "drivetrain.hpp"
void right_velocity(speed){
    speed = speed*20
    RFT.move_voltage(speed);
    RF.move_voltage(speed);
    RB.move_voltage(speed);
}

void left_velocity(speed){
    speed = speed * 20
    LFT.move_voltage(speed);
    LF.move_voltage(speed);
    LB.move_voltage(speed);
}

void brakes_left(){
     LFT.move_brake();
     LF.move_brake();
     LB.move_brake();
}
void brakes_right(){
     RFT.move_brake();
     RF.move_brake();
     RB.move_brake();
}