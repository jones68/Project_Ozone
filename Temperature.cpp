// 
// 
// 

#include "Temperature.h"

#define waitTime 500 //ms
#define inputVoltage 3.3


TMP36G::TMP36G(int TempInput) {
	_tempInput = TempInput;
	pinMode(TempInput, INPUT);
	//Serial.begin(9600);

}

double TMP36G::convertToCelsius(int inputValue) {
	voltage = (inputVoltage / 1023) * inputValue;
	temperature = (voltage - 0.5) * 100;
}

double TMP36G::getTemperature() {
	reading = analogRead(_tempInput);
	return convertToCelsius(reading);
}


