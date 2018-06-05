/*
 * TemperatureSensor.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor() : Sensor() {

	    mraa_init();
	   // this->currentPin= GetPin();
	    this->currentPin= 0;
	    this->aioPin = mraa_aio_init(currentPin);


}

TemperatureSensor::TemperatureSensor(int x) : Sensor(x,true) {

	    mraa_init();
	    this->currentPin=x;
	    this->aioPin = mraa_aio_init(currentPin);

}



int TemperatureSensor::GetStatus(){
	adcValue = mraa_aio_read(aioPin);
	this->R = 1023.0/((float)adcValue)-1.0;    // Promote to float
	R = 100000.0*R;
	temperature = 1.0/(log(R/100000.0)/B+1/298.15)-273.15;
	return (int)(this->temperature);
}

void TemperatureSensor::Run(){

		adcValue = mraa_aio_read(aioPin);

	    this->R = 1023.0/((float)adcValue)-1.0;    // Promote to float
		R = 100000.0*R;

	   temperature = 1.0/(log(R/100000.0)/B+1/298.15)-273.15;

	}


TemperatureSensor::~TemperatureSensor() {
	// TODO Auto-generated destructor stub
}
