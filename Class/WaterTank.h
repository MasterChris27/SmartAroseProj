/*
 * WaterTank.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#ifndef WATERTANK_H_
#define WATERTANK_H_
#include "Valve.h"
#include "WaterLevelSensor.h"

class WaterTank {
public:
	WaterTank();
	WaterTank(int valvePin,int waterLevelPin);
	bool IsValveOpened();
	int GetWaterLevel();
	void Arose(int sec);
	virtual ~WaterTank();
private :
	Valve vlv;
	WaterLevelSensor wLS;
};

#endif /* WATERTANK_H_ */
