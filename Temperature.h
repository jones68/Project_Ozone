// Temperature.h

#ifndef _TEMPERATURE_h
#define _TEMPERATURE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class TMP36G
{
public:
	TMP36G(int TempInput);
	double getTemperature();
private:
	int _tempInput;
	double convertToCelsius(int inputValue);
	double voltage;
	double temperature;
	double reading;
};


#endif

