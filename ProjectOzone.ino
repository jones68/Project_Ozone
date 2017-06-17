

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
/*NO2 no2(no2pin);
TMP36G tmp(tmpPin);
Motor motor(motorPin);
PM25 pm25(pm25wave, pm25out);
SDCard sd(sdcs);
O3 O3_1(o3_1);
O3 O3_2(o3_2);*/
System sys(sdcs);


bool sdcard;


void setup()
{	
	Serial.begin(9600);
	//sd.init();
	
}

void loop()
{
	Serial.println("Starting");
	sys.run();
	Serial.println("Done!");
	delay(100000);
	



}
