// 
// 
// 

#include "Motor.h"

Motor::Motor(int motorPin)
{
	pinMode(motorPin, OUTPUT);
	_motorPin = motorPin;
}

void Motor::run()
{
	digitalWrite(_motorPin, HIGH);
}

void Motor::stop()
{
	digitalWrite(_motorPin, LOW);
}


