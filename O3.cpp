// 
// 
// 

#include "O3.h"

#define Sensitivity -32
#define TIA 499
#define V0 1.65
#define VOLTAGE_IN 5.0

O3::O3(int input)
{
	_input = input;
	pinMode(input, INPUT);
}

double O3::getVoltage()
{
	reading = analogRead(_input);
	//Serial.println(reading);
	//voltage = map(reading, 0, 1023, 0, VOLTAGE_IN);
	//voltage = reading*VOLTAGE_IN / 1023.0;

	return reading;
}

double O3::getO3Reading()
{
	//sensorCalibration = Sensitivity*TIA * 10 ^ -6;
	//double reading = (1.0 / sensorCalibration) * (getVoltage() - V0);
	return getVoltage();
}



