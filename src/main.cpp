/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\taimu                                            */
/*    Created:      Sat Nov 02 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

motor        Left(PORT4, gearSetting::ratio18_1, false);
motor        Left2(PORT3, gearSetting::ratio18_1, false);
motor        Right(PORT2, gearSetting::ratio18_1, true);
motor        Right2(PORT1, gearSetting::ratio18_1, true);
motor        Lift(PORT5, gearSetting::ratio18_1, true);
motor        Lift2(PORT6, gearSetting::ratio18_1, false);
motor        Claw(PORT7, gearSetting::ratio18_1, false);
motor        Claw2(PORT8, gearSetting::ratio18_1, false);
drivetrain   Drivetrain = drivetrain(Left, Right, 319, 295, distanceUnits::mm);
controller   Controller1;

vex::competition Competition;

// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (true)
  {


    Right.spin(directionType::fwd,Controller1.Axis2.position(percentUnits::pct),velocityUnits::pct);
    Right2.spin(directionType::fwd,Controller1.Axis2.position(percentUnits::pct),velocityUnits::pct);
    Left.spin(directionType::fwd,Controller1.Axis3.position(percentUnits::pct),velocityUnits::pct);
    Left2.spin(directionType::fwd,Controller1.Axis3.position(percentUnits::pct),velocityUnits::pct);
    //////////////////Lift/////////////////
    if(Controller1.ButtonR1.pressing())
    {
        Lift.spin(directionType::fwd, 127, velocityUnits::pct);
    }
    else if (Controller1.ButtonR2.pressing()) 
    {
        Lift.spin(directionType::rev, 127, velocityUnits::pct);
    }
    else 
    {
        Lift.stop(brakeType::hold);
    }

 if(Controller1.ButtonR1.pressing())
    {
        Lift2.spin(directionType::fwd, 127, velocityUnits::pct);
    }
    else if (Controller1.ButtonR2.pressing()) 
    {
        Lift2.spin(directionType::rev, 127, velocityUnits::pct);
    }
    else 
    {
        Lift2.stop(brakeType::hold);
    }
    /////////////////Claw///////////////
    if(Controller1.ButtonL1.pressing())
    {
      Claw.spin(directionType::fwd, 127, velocityUnits::pct);
    }
    else if (Controller1.ButtonL2.pressing())
    {
      Claw.spin(directionType::rev, 127, velocityUnits::pct);
    }
    else 
    {
      Claw2.stop(brakeType::hold);
    }

      if(Controller1.ButtonL1.pressing())
    {
      Claw2.spin(directionType::fwd, 127, velocityUnits::pct);
    }
    else if (Controller1.ButtonL2.pressing())
    {
      Claw2.spin(directionType::rev, 127, velocityUnits::pct);
    }
    else 
    {
      Claw2.stop(brakeType::hold);
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}