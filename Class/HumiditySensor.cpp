/*
 * TemperatureSensor.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#include "HumiditySensor.h"


HumiditySensor::HumiditySensor() : Sensor() {

	    mraa_init();
	   // this->currentPin=this->GetPin();
	    this->currentPin=0;
	    this->aioPin = mraa_aio_init(currentPin);


}

HumiditySensor::HumiditySensor(int x) : Sensor(x,true) {

	    mraa_init();
	    this->currentPin=x;
	    this->aioPin = mraa_aio_init(currentPin);

}



int HumiditySensor::GetStatus(){

	status = mraa_aio_read(aioPin);
	return (int)this->status;
}


void HumiditySensor::Run(){

		status = mraa_aio_read(aioPin);

	}


HumiditySensor::~HumiditySensor() {
	// TODO Auto-generated destructor stub
}
