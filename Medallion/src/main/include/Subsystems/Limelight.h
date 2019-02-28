// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef LIMELIGHT_H
#define LIMELIGHT_H
#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Limelight: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	    std::shared_ptr<NetworkTable> table;

public:
	Limelight();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

static constexpr double CAMERAHEIGHT = 0.0;

static constexpr double CAMERAANGOFFSET = 10;

static constexpr double TARGETHEIGHT = 28.59; // we need to find out what this is
bool getTv();

double getTx();

double getTy();

double getTa();

double getTs();

double getDistance();

void setCameraMode(int input);

void setLedMode(int input);

void setPipeline(int input);

};

#endif
