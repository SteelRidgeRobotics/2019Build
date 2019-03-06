// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/HabSki.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

HabSki::HabSki() : frc::Subsystem("HabSki") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    habSkiActuator.reset(new WPI_TalonSRX(6));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void HabSki::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void HabSki::Periodic() {
    // Put code here to be run every loop

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void HabSki::habSkiMoveBackward()
{
    
   double driveTrigger = DriveController->GetRawAxis(3);
   double systemTrigger = SystemsController->GetRawAxis(3);

   if(driveTrigger > 0.8 && systemTrigger >0.8){ 
    habSkiActuator->Set(ControlMode::PercentOutput, -0.5);
   }
   else
   {
       habSkiActuator->Set(ControlMode::PercentOutput, 0.0);
   }
   
}

void HabSki::habSkiMoveForward()
{

    double driveTrigger = DriveController->GetRawAxis(4);
    double systemTrigger = SystemsController->GetRawAxis(4);

    if(driveTrigger > 0.8 && systemTrigger > 0.8)
    {
   
        habSkiActuator->Set(ControlMode::PercentOutput, 0.5);

    }

    else
    {
        habSkiActuator->Set(ControlMode::PercentOutput, 0.0);
    }
    
}
