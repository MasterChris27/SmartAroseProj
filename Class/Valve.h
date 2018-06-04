/*
 * Valve.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#ifndef VALVE_H_
#define VALVE_H_
#include <mraa/gpio.h>
#include <mraa.h> // we can delete it afterwards
#include <stdio.h>
#include <math.h>

class Valve {
public:
	Valve();
	Valve(int x);
	virtual ~Valve();
	void setOpen(bool x);
	bool GetStatus();
	void Apply();

private :
	mraa_gpio_context digPin; // should work
	int currentPin=0;
	bool isOpen=false;

};

#endif /* VALVE_H_ */
