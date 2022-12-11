#include "misc.hpp"
double PID::calculate(double target, double current) {
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