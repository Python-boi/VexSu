#include "misc.hpp"
#include "main.h"

double error;
double integral;
double derivative;
double prevError;
double kP = 1;
double kD = 1;
double kI=1;
double output;

double PIDcalculate(double target, double current) {
  // Proportional Calculation
  error = target - current;

  // Integral Calculation
  integral = integral + error;
  if (error == 0)
    integral = 0;
  if (integral > 12000)
    integral = 12000;

  // Derivative Calculation
  derivative = error - prevError;
  prevError = error;

  // Output Calculation
  output = error * kP + integral * kI + derivative * kD;
  return output;
}