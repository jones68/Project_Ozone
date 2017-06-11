// 
// 
// 

#include "O3.h"

#define Sensitivity 0
#define TIA 499
#define V0 1.65
#define VOLTAGE_IN 5

O3::O3(int input)
{
	_input = input;
	pinMode(input, INPUT);
	Serial.begin(9600);
}

double O3::getVoltage()
{
	reading = analogRead(_input);
	voltage = map(reading, 0, 1023, 0, VOLTAGE_IN);

	return voltage;
}

double O3::getO3Reading()
{
	sensorCalibration = Sensitivity*TIA * 10 ^ -6;
	return (1 / sensorCalibration) * (getVoltage() - V0);
}



