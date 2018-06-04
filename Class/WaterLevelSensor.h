/*
 * WaterLevelSensor.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#ifndef WATERLEVELSENSOR_H_
#define WATERLEVELSENSOR_H_
#include <mraa/gpio.h>
#include <mraa.h> // we can delete it afterwards
#include "Sensor.h"
#include <stdio.h>
#include <math.h>

class WaterLevelSensor: public Sensor {
public:
	WaterLevelSensor();
	WaterLevelSensor(int x);
	virtual ~WaterLevelSensor();
	int GetStatus();
	void Run();

private :
	mraa_gpio_context digPin; // should work
	int currentPin=0;
	int status=0;

};

#endif /* WATERLEVELSENSOR_H_ */
