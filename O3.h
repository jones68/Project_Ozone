// O3.h

#ifndef _O3_h
#define _O3_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class O3
{
public:
	O3(int input);
	double getO3Reading();
private:
	int _input;
	double getVoltage();
	double voltage;
	double sensorCalibration;
	double reading;

};

#endif

