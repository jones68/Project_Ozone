// System.h

#ifndef _SYSTEM_h
#define _SYSTEM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SDCard.h"
#include "Motor.h"

class System
{
protected:


public:
	System(int SDSS);
	void run();
private:
	SDCard sd(int SDSS);
	Motor motor(int motorPin);
	int _ss;




};


#endif

