/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftMotor1            motor         8
// LeftMotor2           motor         9
// RightMotor1            motor         1
// RightMotor2             motor         2
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

controller Controller1 = controller(primary);

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = (Controller1.Axis3.position()) * 0.7;
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = (Controller1.Axis2.position()) * 0.7;
    //int intakeMotorSpeed = (Controller1.Axis1.position() ) * 0.9;

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      LeftMotor1.setVelocity(0, percent);
      LeftMotor2.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      LeftMotor1.setVelocity(leftMotorSpeed, percent);
      LeftMotor2.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      RightMotor1.setVelocity(0, percent);
      RightMotor2.setVelocity(0, percent);

    } else {
      // Set the speed to rightMotorSpeed
      RightMotor1.setVelocity(rightMotorSpeed, percent);
      RightMotor2.setVelocity(rightMotorSpeed, percent);
    }




    // Spin both motors in the forward direction.
    LeftMotor1.spin(reverse);
    LeftMotor2.spin(reverse);
    RightMotor1.spin(forward);
    RightMotor2.spin(forward);

    if(Controller1.ButtonL1.pressing()){
      intakeMotor.spin(reverse, 70, percentUnits::pct);
      
    }else if(Controller1.ButtonL2.pressing()){
      intakeMotor.spin(forward, 70, percentUnits::pct);
      
    }else{
      intakeMotor.stop(hold);
    }
    

    wait(25, msec);
  }
}
