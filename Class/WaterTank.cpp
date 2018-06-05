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
	// printf("\n open valve \n");
	 sleep(sec);
	// printf("\n closing valve\n");
	 vlv.setOpen(false);
	 vlv.Apply();
}

bool WaterTank::ValveOpened(){
	return vlv.GetStatus();
}


int WaterTank::GetWaterLevel(){
	return wLS.GetStatus();}






WaterTank::~WaterTank() {
}

