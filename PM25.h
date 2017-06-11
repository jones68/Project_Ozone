// PM25.h

#ifndef _PM25_h
#define _PM25_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PM25

#define samplingTime 280
{
public:
	PM25(int input, int ouput);
	double readValue();

private:
	void sendPulse();
	double convert(double readVal);
	int _input;
	int _output;
	double readVal;
	double actualVal;
	int sleepTime;
	double dustDensity;
};


#endif

