// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/Elevator.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/ElevatorManual.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Elevator::Elevator() : frc::Subsystem("Elevator") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    elevatorMotor.reset(new WPI_TalonSRX(4));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

     height_Pos = 0.0;
     elevatorMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, kTimeoutMS);
     elevatorMotor->SetSensorPhase(true); //NEEDS TO BE LOOKED INTO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     elevatorMotor->SetInverted(true); // !!!!!!!
     elevatorMotor->SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeoutMS);
     elevatorMotor->SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeoutMS);
     elevatorMotor->ConfigNominalOutputForward(0, kTimeoutMS);
     elevatorMotor->ConfigNominalOutputReverse(0, kTimeoutMS);
     elevatorMotor->ConfigPeakOutputForward(1, kTimeoutMS);
     elevatorMotor->ConfigPeakOutputReverse(-1, kTimeoutMS);
     elevatorMotor->SelectProfileSlot(0, 0);
     elevatorMotor->Config_kF(0, kF, kTimeoutMS);//these guys need to be set too!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     elevatorMotor->Config_kP(0, kP, kTimeoutMS);    //!
     elevatorMotor->Config_kI(0, 0, kTimeoutMS);    //!!
     elevatorMotor->Config_kD(0, 0, kTimeoutMS);    //!!! 
     elevatorMotor->ConfigMotionCruiseVelocity(350, kTimeoutMS); //!!!!
     elevatorMotor->ConfigMotionAcceleration(350, kTimeoutMS); //!!!!!
     elevatorMotor->SetSelectedSensorPosition(0, 0, kTimeoutMS); //look into the first value (initial sensor position)
     //elevatorMotor->ConfigForwardSoftLimitThreshold(26200, kTimeoutMS);
     //elevatorMotor->ConfigReverseSoftLimitThreshold(10, kTimeoutMS);
     elevatorMotor->ConfigClearPositionOnLimitR(true, kTimeoutMS);
     elevatorMotor->ConfigClearPositionOnLimitF(false, kTimeoutMS);
     elevatorMotor->ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, kTimeoutMS);
     elevatorMotor->ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, kTimeoutMS);
     elevatorMotor->ConfigMotionSCurveStrength(3, kTimeoutMS);

}

void Elevator::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new ElevatorManual());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Elevator::Periodic() {
    // Put code here to be run every loop

}

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Elevator::userElevate(std::shared_ptr<frc::Joystick>SystemsController){
    double right_y = -0.75*SystemsController->GetRawAxis(1);

    if(fabs(right_y) < 0.1){
        right_y = 0;
    }

    elevatorMotor->Set(ControlMode::PercentOutput, right_y);
}



void Elevator::encoderReset()
{

    elevatorMotor->SetSelectedSensorPosition(0, 0, kTimeoutMS); //NEEDS TO BE SET

    height_Pos = 0.0;

}

void Elevator::encoderDone()
{
    elevatorMotor->Set(ControlMode::PercentOutput, 0.0);
}

double Elevator::inchesToRotations(double inches)
{
    return inches*fudge*kGearRatio*kSensorUnitsPerRotation*(1/PI);
}

double Elevator::rotationsToInches(double rotations)
{
    return rotations*PI*(1/kGearRatio)*(1/kSensorUnitsPerRotation)*(1/fudge); //... we need to figure out how to convert rotations into inches to do this conversion
}

double Elevator::findDistance(double inches)
{

    double currentPosition = elevatorMotor->GetSelectedSensorPosition();
    double desiredPosition = inchesToRotations(inches);
    double positionDifference = desiredPosition - currentPosition;

    if(!(positionDifference <= 0.0))
    {
        return positionDifference;
    }

    else
    {
        return 0.0;
    }

}

void Elevator::motionMagic(double rotations){
    elevatorMotor->Set(ControlMode::MotionMagic, rotations);
}

void Elevator::elevatorUp()
{
    elevatorMotor->Set(ControlMode::PercentOutput, .2);
}

void Elevator::elevatorDown()
{
    elevatorMotor->Set(ControlMode::PercentOutput, -.6);
}

double Elevator::getPositionInches(){
    double position = elevatorMotor->GetSelectedSensorPosition();

    return rotationsToInches(position);
    

}

double Elevator::getPositionRaw(){
    double position = elevatorMotor->GetSelectedSensorPosition();

    return position;

}

bool Elevator::getLimitR(){
    return elevatorMotor->GetSensorCollection().IsRevLimitSwitchClosed();
    
}
