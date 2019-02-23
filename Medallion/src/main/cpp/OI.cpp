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
#include "Commands/ArmDown.h"
#include "Commands/ArmManual.h"
#include "Commands/ArmUp.h"
#include "Commands/ClawClose.h"
#include "Commands/ClawOpen.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/ElevatorDown.h"
#include "Commands/ElevatorEncoderReset.h"
#include "Commands/ElevatorHome.h"
#include "Commands/ElevatorHomeDown.h"
#include "Commands/ElevatorHomeUp.h"
#include "Commands/ElevatorManual.h"
#include "Commands/ElevatorUp.h"
#include "Commands/LimeLightTrack.h"
#include "Commands/LimelightOff.h"
#include "Commands/PusherIn.h"
#include "Commands/PusherOut.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    systemsController.reset(new frc::Joystick(1));
    
    rJoyBn.reset(new frc::JoystickButton(systemsController.get(), 10));
    rJoyBn->WhenPressed(new PusherOut());
    lJoyBn.reset(new frc::JoystickButton(systemsController.get(), 9));
    lJoyBn->WhenPressed(new PusherIn());
    back.reset(new frc::JoystickButton(systemsController.get(), 7));
    back->WhenPressed(new ElevatorEncoderReset());
    rBump.reset(new frc::JoystickButton(systemsController.get(), 6));
    rBump->WhenPressed(new ClawOpen());
    lBump.reset(new frc::JoystickButton(systemsController.get(), 5));
    lBump->WhenPressed(new ClawClose());
    a.reset(new frc::JoystickButton(systemsController.get(), 1));
    a->WhenPressed(new ArmDown());
    b.reset(new frc::JoystickButton(systemsController.get(), 2));
    //b->WhenPressed(new ArmUp(0));
    x.reset(new frc::JoystickButton(systemsController.get(), 3));
    x->WhenPressed(new ElevatorDown());
    y.reset(new frc::JoystickButton(systemsController.get(), 4));
    //y->WhenPressed(new ElevatorUp(0));
    driveController.reset(new frc::Joystick(0));
    
    dRBump.reset(new frc::JoystickButton(driveController.get(), 8));
    dRBump->WhileHeld(new LimeLightTrack());

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("LimelightOff", new LimelightOff());
    frc::SmartDashboard::PutData("LimeLightTrack", new LimeLightTrack());
    frc::SmartDashboard::PutData("ElevatorHome", new ElevatorHome());
    frc::SmartDashboard::PutData("PusherIn", new PusherIn());
    frc::SmartDashboard::PutData("PusherOut", new PusherOut());
    frc::SmartDashboard::PutData("ClawClose", new ClawClose());
    frc::SmartDashboard::PutData("ClawOpen", new ClawOpen());
    frc::SmartDashboard::PutData("ArmDown", new ArmDown());
    //frc::SmartDashboard::PutData("ArmUp", new ArmUp());
    frc::SmartDashboard::PutData("ElevatorEncoderReset", new ElevatorEncoderReset());
    frc::SmartDashboard::PutData("ElevatorDown", new ElevatorDown());
    //frc::SmartDashboard::PutData("ElevatorUp", new ElevatorUp());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    y->ToggleWhenPressed(new ElevatorUp(Robot::elevator->HPOS1));
    y->ToggleWhenPressed(new ElevatorUp(Robot::elevator->CPOS1));
    y->ToggleWhenPressed(new ElevatorUp(Robot::elevator->HPOS2));
    y->ToggleWhenPressed(new ElevatorUp(Robot::elevator->CPOS2));
    y->ToggleWhenPressed(new ElevatorUp(Robot::elevator->HPOS3));
    y->ToggleWhenPressed(new ElevatorUp(Robot::elevator->CPOS3));
    y->ToggleWhenPressed(new ElevatorDown());

    b->ToggleWhenPressed(new ArmUp(Robot::arm->POS1));
    b->ToggleWhenPressed(new ArmUp(Robot::arm->POS2));
    b->ToggleWhenPressed(new ArmUp(Robot::arm->POS3));
    b->ToggleWhenPressed(new ArmDown());

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getDriveController() {
   return driveController;
}

std::shared_ptr<frc::Joystick> OI::getSystemsController() {
   return systemsController;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
