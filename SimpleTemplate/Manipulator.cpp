#include "Manipulator.h"

Manipulator::Manipulator()
{
	flywheel = new Talon(FLYWHEEL_MOTOR_CHANNEL);
	flywheelEncoder = new Encoder(FLYWHEEL_ENCODER_CHANNEL_A, FLYWHEEL_ENCODER_CHANNEL_B);
	timer = new Timer();
	timer->Start();
	
	init = true;
	initTime = 0;
	deltaTime = 0;
	initTicks = 0;
	deltaTicks = 0;
	ticksPerMinute = 0;
}

Manipulator::~Manipulator()
{
	delete flywheel;
	delete flywheelEncoder;
	delete timer;
	
	flywheel = NULL;
	flywheelEncoder = NULL;
	timer = NULL;
}

void Manipulator::SetVelocity(double speed)
{
	flywheel->Set(speed, SYNC_STATE_OFF);
}

double Manipulator::GetVelocity()
{
	return flywheel->Get();
}

double Manipulator::GetRPM()
{	
	if(init)
	{
		initTime = timer->Get();
		initTicks = flywheel->Get();
		deltaTime = 0;
		deltaTicks = 0;
		ticksPerMinute = 0;
		init = false;
	}
	
	deltaTime = timer->Get() - initTime;
	deltaTicks = flywheel->Get() - initTicks;
	
	if(deltaTime == TIME_COMPARISON)
	{
		ticksPerMinute = deltaTicks * TIME_COMPARISON * MINUTE_CONVERSION;
		rpm = ticksPerMinute / TICKS_PER_ROTATION;
		init = true;
	}
	return rpm;
}


