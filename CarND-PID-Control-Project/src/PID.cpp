#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp=Kp_;
  Ki=Ki_;
  Kd=Kd_;
  
  p_error=0;
  i_error=0;
  d_error=0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error=cte-p_error; //p_error is the previuos cte as it is not updated.
  p_error=cte;
  i_error+=cte;
  

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
   std::cout << "P= " << Kp*p_error << " I=" << Ki*i_error 
     		<< " D= " << Kd*d_error 
                    << std::endl;
  
  return Kp*p_error+Ki*i_error+Kd*d_error;  // TODO: Add your total error calc here!
}