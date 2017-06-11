// NO2.h

#ifndef _NO2_h
#define _NO2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class NO2 {
public:
	NO2(int input);
	double getNO2Reading();
private:
	int _input;
	double reading;
	double sensorCalibration;
	double voltage;
	double getVoltage();
};

#endif

