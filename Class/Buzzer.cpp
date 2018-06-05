/*
 * Buzzer.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#include "Buzzer.h"

Buzzer::Buzzer() {

    mraa_init();
	this->currentPin=0;
	this->buzzPin = mraa_gpio_init(this->currentPin);
    mraa_gpio_dir(this->buzzPin, MRAA_GPIO_OUT);

}

Buzzer::Buzzer(int x) {

    mraa_init();
	this->currentPin=x;
	this->buzzPin = mraa_gpio_init(this->currentPin);
    mraa_gpio_dir(this->buzzPin, MRAA_GPIO_OUT);

}


void Buzzer::Run(int sec){
	int i=0;
	this->status=1;

	while(i<=sec){
		mraa_gpio_write(buzzPin, 1);
		usleep(333333);
		mraa_gpio_write(buzzPin, 0);
		usleep(666667);
		i++;
	}

	status=0;

}

int Buzzer::GetStatus(){

	return this->status;

}



void Buzzer::SetPin(int x){
	this->currentPin=x;
}
int Buzzer::GetPin(){
	return this->currentPin;
}





Buzzer::~Buzzer() {
	// TODO Auto-generated destructor stub
}

