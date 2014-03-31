#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "WPILib.h"
#include "Macros.h"

class Manipulator
{
public:
	Manipulator();
	~Manipulator();
	
	void SetVelocity(double speed);
	double GetVelocity();
	
	double GetRPM();
	
private:
	Talon *flywheel;
	Encoder *flywheelEncoder;
	Timer *timer;
	bool init;
	double initTime;
	double deltaTime;
	double initTicks;
	double deltaTicks;
	double ticksPerMinute;
	double rpm;
};

#endif
