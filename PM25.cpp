// 
// 
// 

#include "PM25.h"


#include "Arduino.h"


PM25::PM25(int input, int output)
{
	_input = input;
	_output = output;
	pinMode(input, INPUT);
	pinMode(output, OUTPUT);
	Serial.begin(9600);
}

double PM25::readValue()
{
	//sendPulse();
	readVal = analogRead(_input);
	Serial.println(readVal);
	actualVal = convert(readVal);
	delay(1000);
	return actualVal;
}

void PM25::sendPulse() {
	digitalWrite(_output, HIGH);
	long time = micros();
	while (micros() - time > 320)
	{
		digitalWrite(_output, LOW);
	}

}

double PM25::convert(double readVal) {

	delayMicroseconds(samplingTime);
	double voltage = readVal*(5.0 / 1024);
	dustDensity = (0.17*voltage - 0.1) * 1000;

	return dustDensity;
}



