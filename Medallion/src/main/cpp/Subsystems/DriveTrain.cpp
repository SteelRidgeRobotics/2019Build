// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/DriveTrain.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/DriveWithJoystick.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    frontLeft.reset(new WPI_TalonSRX(0));
    frontRight.reset(new WPI_TalonSRX(2));
    backLeft.reset(new WPI_VictorSPX(1));
    backRight.reset(new WPI_VictorSPX(3));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    backLeft->Follow(*frontLeft); //left back to follow left front
    backRight->Follow(*frontRight); //right back to follow right front

    backRight->SetInverted(true);
    frontRight->SetInverted(true);

    backLeft->SetNeutralMode(NeutralMode::Brake);
    frontLeft->SetNeutralMode(NeutralMode::Brake);
    backRight->SetNeutralMode(NeutralMode::Brake);
    frontRight->SetNeutralMode(NeutralMode::Brake);

    
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new DriveWithJoystick());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveTrain::Periodic() {
    // Put code here to be run every loop

}

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::userDrive(std::shared_ptr<frc::Joystick>DriveController)

{
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double left_y = -1*DriveController->GetRawAxis(1);
    double right_y = -1*DriveController->GetRawAxis(5);
    int l_bump = DriveController->GetRawButton(5);
    int r_bump = DriveController->GetRawButton(6);
    double tx = table->GetNumber("tx",0.0);
    double ty = table->GetNumber("ty",0.0);      
    double left_command = 0.0;
    double right_command = 0.0;
    double KpAim = 0.001;
    double steering_adjust = 0.0;
;
    

    if (fabs(left_y) < 0.1) {
        left_y = 0;
    }

    if (fabs(right_y) < 0.1 ) {
        right_y = 0;
    }

    if (l_bump == 1) {
        left_y = 0.6*left_y;
        right_y = 0.6*right_y;

    }

    frontLeft->Set(ControlMode::PercentOutput, left_y);
    frontRight->Set(ControlMode::PercentOutput, right_y);

// Vision Tracking 
    if(r_bump==1) {


if (ty == 0.0)
{
        // We don't see the target, seek for the target by spinning in place at a safe speed.
        steering_adjust = 0.3;
}
else
{
        // We do see the target, execute aiming code
        double heading_error = tx;
        steering_adjust = KpAim * tx;
}

left_command+=steering_adjust;
right_command-=steering_adjust;

    frontLeft->Set(ControlMode::PercentOutput, left_command);
    frontRight->Set(ControlMode::PercentOutput, right_command);

    if(r_bump != 1)

    {

        table->PutNumber("ledMode", 0);

        table->PutNumber("camMode", 1);

        //nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 0); //keep the leds off while not in use

        //nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("camMode", 1); //have the camera in driver mode(no processing) while not used for tracking
    }

    else
    {   
        table->PutNumber("ledMode", 3); //turn on the led for tracking

        table->PutNumber("camMode", 0); //set the camera in tracking mode

    }
    
}

} 
