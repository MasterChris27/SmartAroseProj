/*
 * Led.h
 *
 *  Created on: 1 juin 2018
 *      Author: boza
 */

#ifndef LED_H_
#define LED_H_
#include <mraa.h>

class Led {
public:
	Led();
	virtual ~Led();
	void SetPin(int x);
	Led(int pin);
	int GetPin();
	int GetStatus();
	void Run(int y);

	private :

	mraa_gpio_context ledPin; // should work
	int currentPin=0;
	int status=0;
	int toggle=0;
};

#endif /* LED_H_ */
