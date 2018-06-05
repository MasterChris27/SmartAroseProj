/*
 * Plant.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#include "Plant.h"

Plant::Plant() {

	wES = WaterExistanceSensor(0);
	tS = TemperatureSensor(1);
	hS= HumiditySensor(2);

}
Plant::Plant(int waterPin,int tempPin,int humidityPin) {

	wES =WaterExistanceSensor(waterPin);
	tS = TemperatureSensor(tempPin);
	hS= HumiditySensor(humidityPin);
}


int Plant::GetTemp(){

	return tS.GetStatus();
}
int Plant::GetWaterExistance(){

	return wES.GetStatus();
}
int Plant::GetHumidity(){ // not defined as a unit of measurement

	return hS.GetStatus();

}





Plant::~Plant() {
	// TODO Auto-generated destructor stub
}

