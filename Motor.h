// Motor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Motor
{
public:
	Motor(int motorPin);
	void run();
	void stop();
private:
	int _motorPin;


};


#endif

