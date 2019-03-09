// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

#include <frc/Commands/Scheduler.h>
#include <frc/SmartDashboard/SmartDashboard.h>

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<Elevator> Robot::elevator;
std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Claw> Robot::claw;
std::shared_ptr<Pusher> Robot::pusher;
std::shared_ptr<Limelight> Robot::limelight;
std::shared_ptr<HabSki> Robot::habSki;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

	cs::UsbCamera camera0;
	//cs::UsbCamera camera1;


void Robot::RobotInit() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    frc::SmartDashboard::PutData(driveTrain.get());
    elevator.reset(new Elevator());
    frc::SmartDashboard::PutData(elevator.get());
    arm.reset(new Arm());
    frc::SmartDashboard::PutData(arm.get());
    claw.reset(new Claw());
    pusher.reset(new Pusher());
    limelight.reset(new Limelight());
    habSki.reset(new HabSki());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// Add commands to Autonomous Sendable Chooser
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	chooser.AddOption("DriveWithJoystick", new DriveWithJoystick());
	chooser.AddOption("ElevatorHome", new ElevatorHome());

	chooser.SetDefaultOption("ElevatorHome", new ElevatorHome());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	frc::SmartDashboard::PutData("Auto Modes", &chooser);

	camera0 = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera0.SetResolution(250,250);
		camera0.SetFPS(30);

	//camera1 = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
	//camera1.SetResolution(480,480);
	//camera1.SetFPS(20);
	
	
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();

	//frc::SmartDashboard::PutNumber("Ele_Pos", Robot::elevator->getPosition());

	TeleopPeriodic();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
		
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();

	frc::SmartDashboard::PutNumber("Ele_Pos_Raw", Robot::elevator->getPositionRaw());

	frc::SmartDashboard::PutNumber("Ele_Pos_Inches", Robot::elevator->getPositionInches());

	frc::SmartDashboard::PutNumber("Arm_Pos", Robot::arm->getPosition());

	frc::SmartDashboard::PutNumber("Limelight_Distance", Robot::limelight->getDistance());

}

#ifndef RUNNING_FRC_TESTS
int main(int argc, char** argv) {
    return frc::StartRobot<Robot>();
}
#endif
