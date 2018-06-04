/*
 * WaterExistanceSensor.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#ifndef WATEREXISTANCESENSOR_H_
#define WATEREXISTANCESENSOR_H_
#include <mraa/gpio.h>
#include <mraa.h> // we can delete it afterwards
#include "Sensor.h"
#include <stdio.h>
#include <math.h>

class WaterExistanceSensor :public Sensor {
public:
	WaterExistanceSensor();
	WaterExistanceSensor(int x);
	virtual ~WaterExistanceSensor();

	int GetStatus();
	void Run();

private :
	mraa_gpio_context digPin; // should work
	int currentPin=0;
	int status=0;

};

#endif /* WATEREXISTANCESENSOR_H_ */
