/*
 * Button.h
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <mraa.h>
class Button {
public:
	Button();
	Button(int x);
	virtual ~Button();

	void SetPin(int x);
	int GetPin();
	int GetStatus();

	void WaitCommand(int y);
private :
		mraa_gpio_context btnPin; // should work
		int currentPin=0;
		int status=0;
		int toggle =0;


};

#endif /* BUTTON_H_ */
