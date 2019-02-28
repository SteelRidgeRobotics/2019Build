// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/Limelight.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Limelight::Limelight() : frc::Subsystem("Limelight") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

}

void Limelight::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new LimelightOff());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Limelight::Periodic() {
    // Put code here to be run every loop

}

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

bool Limelight::getTv()

{
    double tv = table->GetNumber("tv", 0.0); 

    if (tv != 0.0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

double Limelight::getTx()
{
    double tx = table->GetNumber("tx", 0.0);

    return tx;
}

double Limelight::getTy()
{
    double ty = table->GetNumber("ty", 0.0);

    return ty;
}

double Limelight::getTa()
{
    double ta = table->GetNumber("ta", 0.0);

    return ta;
}

double Limelight::getTs()
{
    double ts = table->GetNumber("ts", 0.0);

    return ts;
}

double Limelight::getDistance() //d = (h2(height of obj)-h1(height of camera)) / tan(a1(ang above)+a2(ang below to ground))

{

double h1 = CAMERAHEIGHT;
double h2 = TARGETHEIGHT;
double hDif = h2 - h1;
double a1 = CAMERAANGOFFSET;
double a2 = getTy();
double aSum = a1 + a2; 

double distance = (hDif) / tan(aSum);

return distance;

}

void Limelight::setCameraMode(int input)
{
    table->PutNumber("cameraMode", input);
}

void Limelight::setLedMode(int input)
{
    table->PutNumber("ledMode", input);
}

void Limelight::setPipeline(int input)
{
    table->PutNumber("pipeline", input);
}
