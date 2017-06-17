// SDCard.h

#ifndef _SDCARD_h
#define _SDCARD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SPI.h"
#include "SD.h"

class SDCard
{
public:
	SDCard(int ss);
	File dataFile;
	int ss;
	bool init();
	void processData(int readNum, long time, double no2read, double o3read, double o3_2read, double pm25read, double tempRead);
	void shutDown();
	File getFile();

private:

	int _ss;
	bool initFlag;
	bool dataFlag;
};


#endif

