#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "WPILib.h"
#include "Macros.h"

class Manipulator
{
public:
	Manipulator();
	~Manipulator();
	
	void setVelocity(double speed);
	double getVelocity();
	
	void setRPM(double targetRPM);
	double getRPM();
	
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
	double velocity;
};

#endif
