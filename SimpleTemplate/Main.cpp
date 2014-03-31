#include "WPILib.h"
#include "Manipulator.h"
#include "OperatorInterface.h"
#include "Macros.h"

class Main : public IterativeRobot
{
public:
	
	Manipulator *manip;
	OperatorInterface *oi;

	Main()
	{
		manip = new Manipulator();
		oi = new OperatorInterface();
		
		oi->dashboard->init();
	}

	void RobotInit()
	{
	
	}
	
	void DisabledInit()
	{
	
	}
	
	void AutonomousInit()
	{
	
	}
	
	void TeleopInit()
	{

	}

	void TestInit()
	{
		
	}
	
	void DisabledPeriodic()
	{
	
	}
	
	void AutonomousPeriodic()
	{
	
	}
	
	void TeleopPeriodic()
	{

	}
	
};

START_ROBOT_CLASS(Main);
