// System.h

#ifndef _SYSTEM_h
#define _SYSTEM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Temperature.h"
#include "SDCard.h"
#include "PM25.h"
#include "O3.h"
#include "Motor.h"
#include "NO2.h"

class System
{
protected:


public:
	System(int sdss);
	void run();
private:
	int _ss;




};


#endif

