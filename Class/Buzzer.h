/*
 * Buzzer.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include <mraa/gpio.h>
#include <mraa.h> // we can delete it afterwards
#include "Sensor.h"
#include <stdio.h>
#include <math.h>


class Buzzer {
public:
	Buzzer();
	Buzzer(int x);
	virtual ~Buzzer();
	void SetPin(int x);
	int GetPin();
	int GetStatus();
	void Run(int y);

	private :
		mraa_gpio_context buzzPin; // should work
		int currentPin=0;
		int status=0;
		int toggle=0;


};

#endif /* BUZZER_H_ */
