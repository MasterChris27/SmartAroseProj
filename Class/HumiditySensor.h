/*
 * TemperatureSensor.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */



#include <mraa/gpio.h>
#include <mraa.h> // we can delete it afterwards
#include "Sensor.h"
#include <stdio.h>
#include <math.h>

class HumiditySensor :public Sensor {
public:
	HumiditySensor();
	HumiditySensor(int x);
	virtual ~HumiditySensor();
	int GetStatus();
	void Run();


private :
	 	mraa_aio_context   aioPin;           // used as AIO context
	 	int currentPin=0;
	    float status;
};

