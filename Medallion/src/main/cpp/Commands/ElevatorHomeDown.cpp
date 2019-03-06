// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Commands/ElevatorHomeDown.h"
#include <iostream>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ElevatorHomeDown::ElevatorHomeDown(double timeout) : frc::TimedCommand(timeout) {
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ElevatorHomeDown::Initialize() {
    std::cout << "Homing Elevator Down!" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void ElevatorHomeDown::Execute() {
    Robot::elevator->elevatorDown();
}

// Called once after command times out
void ElevatorHomeDown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorHomeDown::Interrupted() {

}
