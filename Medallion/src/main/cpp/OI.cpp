// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/smartdashboard/SmartDashboard.h"
#include "Commands/ArmManual.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/ElevatorDown.h"
#include "Commands/ElevatorEncoderReset.h"
#include "Commands/ElevatorManual.h"
#include "Commands/ElevatorUp.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    systemsController.reset(new frc::Joystick(1));
    
    y.reset(new frc::JoystickButton(systemsController.get(), 4));
    y->WhenPressed(new ElevatorUp(0));
    driveController.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("ElevatorEncoderReset", new ElevatorEncoderReset());
    frc::SmartDashboard::PutData("ElevatorDown", new ElevatorDown());
    frc::SmartDashboard::PutData("ElevatorUp", new ElevatorUp());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getDriveController() {
   return driveController;
}

std::shared_ptr<frc::Joystick> OI::getSystemsController() {
   return systemsController;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
