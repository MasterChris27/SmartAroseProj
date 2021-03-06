/*
 * WaterTank.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#include "WaterTank.h"

WaterTank::WaterTank() {

	wLS = WaterLevelSensor();
	vlv = Valve();

}

WaterTank::WaterTank(int valvePin,int waterLevelPin){

	wLS = WaterLevelSensor(waterLevelPin);
	vlv = Valve(valvePin);
}

void WaterTank::Arose(int sec){
	 vlv.setOpen(true);
	 vlv.Apply();
	 sleep(sec);
	 vlv.setOpen(false);
	 vlv.Apply();
}

bool WaterTank::IsValveOpened(){
	return vlv.GetStatus();
}


int WaterTank::GetWaterLevel(){
	return wLS.GetStatus();}






WaterTank::~WaterTank() {
}

