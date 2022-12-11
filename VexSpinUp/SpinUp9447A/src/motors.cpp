#include "main.h"

//Controller Definition
pros::Controller master(CONTROLLER_MASTER);

// Motor Definitions //
// Lift Definition
pros::Motor flywheel(13, MOTOR_GEARSET_6, 1, MOTOR_ENCODER_COUNTS);

// Intake Definition
pros::Motor intake(15, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_COUNTS);

//Drive Base Definitions
pros::Motor LF(6, MOTOR_GEARSET_6, 1, MOTOR_ENCODER_COUNTS), 
            LFT(8, MOTOR_GEARSET_6, 1, MOTOR_ENCODER_COUNTS),
            LB(10, MOTOR_GEARSET_6, 1, MOTOR_ENCODER_COUNTS),
            RF(1, MOTOR_GEARSET_6, 0, MOTOR_ENCODER_COUNTS),
            RFT(3, MOTOR_GEARSET_6, 0, MOTOR_ENCODER_COUNTS),
            RB(5, MOTOR_GEARSET_6, 0, MOTOR_ENCODER_COUNTS);
//sensor Definitions//
pros::Distance Dist(14);

pros::ADIDigitalOut loader('A');