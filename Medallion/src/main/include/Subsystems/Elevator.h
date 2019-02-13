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
	std::shared_ptr<frc::DigitalInput> lowLS;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	double height_Pos;
public:
	Elevator();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	static constexpr double MIN = 0; 

	static constexpr double HPOS1 = 0;

	static constexpr double HPOS2 = 0;

	static constexpr double HPOS3 = 0; //all these need to be set!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	static constexpr double CPOS1 = 0;

	static constexpr double CPOS2 = 0;

	static constexpr double CPOS3 = 0;

	static constexpr double MAX = 0;

	void userElevate(std::shared_ptr<frc::Joystick>SystemsController);

	void encoderReset();

	void encoderDone();

	bool isMove();

	double inchesToRotations(double inches);

};

#endif
