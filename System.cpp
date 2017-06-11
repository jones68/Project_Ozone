// 
// 
// 

#include "System.h"
#include "Pm25.h"
#include "NO2.h"
#include "O3.h"
#include "Temperature.h"
#include "SDCard.h"
#include "Motor.h"

#define pm25_in 1
#define pm25_out 2

#define tempIn 3
#define O3_in 4
#define NO2_in 5

#define shutOff1 20
#define shutOff2 21

#define motorPin 6


System::System(int SDSS)
{
	_ss = SDSS;
}

void System::run()
{
	SDCard sd(_ss);
	PM25 pm25(pm25_in, pm25_out);
	NO2 no2(NO2_in);
	O3 o3(O3_in);
	TMP36G tmp(tempIn);
	Motor motor(motorPin);

	int readNum = 1;
	unsigned long runtime = millis();

	sd.init();
	int tryCounter = 3;
	while (sd.getFile() == NULL && tryCounter > 0)
	{
		sd.init();
		tryCounter--;
	}

	if (sd.getFile() == NULL && tryCounter == 0)
	{
		return;
	}
	else
	{
		motor.run();
	}

	if (digitalRead(shutOff1) == HIGH && digitalRead(shutOff2) == HIGH)
	{
		unsigned long startTime = millis();
		while (digitalRead(shutOff1) == HIGH && digitalRead(shutOff2) == HIGH)
		{
			if (millis() - startTime > 3000)
			{
				motor.stop();
				sd.shutDown();
			}
		}
	}

	while (digitalRead(shutOff1) == LOW || digitalRead(shutOff2) == LOW)
	{
		sd.processData(readNum, millis() - runtime, no2.getNO2Reading(), o3.getO3Reading(), pm25.readValue(), tmp.getTemperature());
		readNum++;
	}

}


