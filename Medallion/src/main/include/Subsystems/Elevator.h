// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Elevator: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<WPI_TalonSRX> elevatorMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	double height_Pos;
public:
	Elevator();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	static constexpr double MIN = 0; 

	static constexpr double HPOS1 = 3;

	static constexpr double HPOS2 = 46.3 - 20.75;

	static constexpr double HPOS3 = 50.0; //all these need to be set!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	static constexpr double CPOS1 = 26.8 - 20.75;

	static constexpr double CPOS2 = 54.8 - 20.75;

	static constexpr double CPOS3 = 50.0;

	static constexpr double MAX = 55.0;

	static const int kGearRatio = 25;

	static const int kSensorUnitsPerRotation = 80;

	static constexpr double kF = 1023.0/701.0;

	static constexpr double kP = 0.0;

	static constexpr double kIzone = 0.0;

	static constexpr double kI = 0.0;

	static constexpr double kD = 0.0;

	static const int kTimeoutMS = 30;

	void userElevate(std::shared_ptr<frc::Joystick>SystemsController);

	void encoderReset();

	void encoderDone();

	bool isMove();

	double inchesToRotations(double inches);

	double rotationsToInches(double rotations);

	double findDistance(double inches);

	void motionMagic(double rotations);

	void elevatorUp();
	
	void elevatorDown();

	double getPosition();
};

#endif
