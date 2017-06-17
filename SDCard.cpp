// 
// 
// 

//#include "SD\SD_t3.h"
#include "SD.h"
#include <SPI.h>
#include "SDCard.h"


SDCard::SDCard(int ss) {
	Serial.begin(9600);
	_ss = ss;

	initFlag = false;
	dataFlag = false;


	//pinMode(_ss, OUTPUT);

}

bool SDCard::init() {
	
	if (!SD.begin(10))
		return initFlag;
	else initFlag = true;

	dataFile = SD.open("data.txt", FILE_WRITE);

	

	if (!dataFile)
		return dataFlag;
	else 
		dataFlag = true;
	
	Serial.println(dataFlag && initFlag);

	return dataFlag && initFlag;

}


void SDCard::processData(int readNum, long time, double no2read, double o3read, double o3_2read, double pm25read, double tempRead)
{

	dataFile.print(readNum);
	dataFile.print(":::: Time (ms): ");
	dataFile.print(time);
	dataFile.print(", NO: ");
	dataFile.print(no2read);
	dataFile.print(", O3: ");
	dataFile.print(o3read);
	dataFile.print(", O3-2: ");
	dataFile.print(o3_2read);
	dataFile.print(", PM2.5: ");
	dataFile.print(pm25read);
	dataFile.print(", TMP: ");
	dataFile.println(tempRead);

}

void SDCard::shutDown()
{
	dataFile.println("");
	dataFile.println("Data Collection Finished!");
	dataFile.close();
}

File SDCard::getFile()
{
	return dataFile;
}

