/*
 * Plant.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#ifndef PLANT_H_
#define PLANT_H_
#include "TemperatureSensor.h"
#include "WaterExistanceSensor.h"
#include "HumiditySensor.h"

class Plant {
public:
	Plant();
	virtual ~Plant();
	Plant(int waterPin,int tempPin,int humidityPin) ;
	int GetTemp();
	int GetWaterExistance();
	int GetHumidity();

private :
	WaterExistanceSensor wES;
	TemperatureSensor tS;
	HumiditySensor hS ;
};

#endif /* PLANT_H_ */
