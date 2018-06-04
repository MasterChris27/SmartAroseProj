/*
 * WaterExistanceSensor.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#include "WaterExistanceSensor.h"



WaterExistanceSensor::WaterExistanceSensor() : Sensor() {

    mraa_init();
	//this->currentPin=Sensor::GetPin(); // will never get called anyway
	this->currentPin=0;
    this->digPin = mraa_gpio_init(this->currentPin);

}


WaterExistanceSensor::WaterExistanceSensor(int x):Sensor(x,true) {

    mraa_init();
    this->currentPin=x;
    digPin = mraa_gpio_init(x);

}



int WaterExistanceSensor::GetStatus(){

	return status;

}

void WaterExistanceSensor::Run(){ ///how does it work
	status=mraa_gpio_read(digPin);
}


WaterExistanceSensor::~WaterExistanceSensor() {
	// TODO Auto-generated destructor stub
}
