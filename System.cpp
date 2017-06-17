// 
// 
// 

#include "Temperature.h"
#include "System.h"
#include "SDCard.h"
#include "PM25.h"
#include "O3.h"
#include "Motor.h"
#include "NO2.h"

#define no2pin 14
#define tmpPin 18 
#define o3_1 16
#define o3_2 15
#define pm25out 17
#define pm25wave 5

#define motorPin 3
#define sdcs 10

#define shutOff1 20
#define shutOff2 21



System::System(int sdss)
{
	Serial.begin(9600);
}

void System::run()
{
	NO2 no2(no2pin);
	TMP36G tmp(tmpPin);
	Motor motor(motorPin);
	PM25 pm25(pm25wave, pm25out);
	SDCard sd(sdcs);
	O3 O3_1(o3_1);
	O3 O3_2(o3_2);

	int readNum = 1;
	unsigned long runtime = millis();

	sd.init();

	int tryCounter = 3;
	while (sd.getFile() == NULL && tryCounter > 0)
	{
		sd.init();
		tryCounter--;
		Serial.println("Failed Attempt");
	}

	if (sd.getFile() == NULL && tryCounter == 0)
	{
		Serial.println("Failed");
		return;
	}
	else
	{
		Serial.println("Initialized!");
		motor.run();
	}

	while (millis() - runtime < 30000 && sd.getFile()) {
		sd.processData(readNum, millis() - runtime, no2.getNO2Reading(), O3_1.getO3Reading(), O3_2.getO3Reading(), pm25.readValue(), tmp.getTemperature());
		readNum++;
		Serial.print("Time: ");
		Serial.println(millis() - runtime);
	}
	sd.shutDown();

	/*if (digitalRead(shutOff1) == HIGH && digitalRead(shutOff2) == HIGH)
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
		sd.processData(readNum, millis() - runtime, no2.getNO2Reading(), O3_1.getO3Reading(), O3_2.getO3Reading(), pm25.readValue(), tmp.getTemperature());
		readNum++;
	}*/


}


