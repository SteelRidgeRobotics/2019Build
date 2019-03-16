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

    //THESE NEED TO BE COMMENTED OUT WHEN USING THE PRACTICE ROBOT!!!
    backLeft.reset(new WPI_VictorSPX(1));
    backRight.reset(new WPI_VictorSPX(3));


    //THSE NEED TO BE UNCOMMENTED WHEN USING THE PRACTICE ROBOT!!!
    //backLeft.reset(new WPI_TalonSRX(1));
    //backRight.reset(new WPI_TalonSRX(3));
    

    limelightdrive.reset(new frc::DifferentialDrive(*frontLeft, *frontRight));
    limelightdrive->SetSafetyEnabled(false);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    backLeft->Follow(*frontLeft); //left back to follow left front
    backRight->Follow(*frontRight); //right back to follow right front

    backRight->SetInverted(true);
    frontRight->SetInverted(true);

    backLeft->SetNeutralMode(NeutralMode::Brake);
    frontLeft->SetNeutralMode(NeutralMode::Brake);
    backRight->SetNeutralMode(NeutralMode::Brake);
    frontRight->SetNeutralMode(NeutralMode::Brake);

    frontLeft->EnableCurrentLimit(false);
    frontRight->EnableCurrentLimit(false);
    

    
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
    /*
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    static constexpr double TARGET_AREA = 3;
    */
    double left_y = -0.7*DriveController->GetRawAxis(1);
    double right_y = -0.7*DriveController->GetRawAxis(5);
    int l_bump = DriveController->GetRawButton(5);
    //int r_bump = DriveController->GetRawButton(6);

    

    if (fabs(left_y) < 0.1) {
        left_y = 0;
    }

    if (fabs(right_y) < 0.1 ) {
        right_y = 0;
    }

    if (l_bump == 1) {
        left_y = 0.5*left_y;
        right_y = 0.5*right_y;

    }

    frontLeft->Set(ControlMode::PercentOutput, left_y);
    frontRight->Set(ControlMode::PercentOutput, right_y);

   } 


void DriveTrain::setMotors(double leftspeed, double rightspeed){
    frontLeft->Set(ControlMode::PercentOutput, leftspeed);
    frontRight->Set(ControlMode::PercentOutput, rightspeed);

    frontLeft->EnableCurrentLimit(false);
    frontRight->EnableCurrentLimit(false);
   }

void DriveTrain::limelightAuto(double move, double turn){
    limelightdrive->ArcadeDrive(move, turn, false);
    frontLeft->ConfigPeakCurrentLimit(10, 30);
    frontRight->ConfigPeakCurrentLimit(10, 30);
    frontLeft->EnableCurrentLimit(true);
    frontRight->EnableCurrentLimit(true);
}

void DriveTrain::setInvert(bool value){
    frontRight->SetInverted(value);
    backRight->SetInverted(value);
}