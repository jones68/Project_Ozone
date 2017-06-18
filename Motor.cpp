// 
// 
// 

#include "Motor.h"

Motor::Motor(int motorpin)
{
	pinMode(motorpin, OUTPUT);
	_motorPin = motorpin;
}

void Motor::run()
{
	digitalWrite(_motorPin, HIGH);
}

void Motor::stop()
{
	digitalWrite(_motorPin, LOW);
}


