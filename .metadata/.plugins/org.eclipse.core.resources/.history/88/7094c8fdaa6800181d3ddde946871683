/*
 * Sensor.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */

#include "Sensor.h"

	int sensorPin=0;
	bool directionIn=true;

Sensor::Sensor() {

	int sensorPin = 0;
	bool directionIn = true;
}

Sensor::Sensor(int x,bool y) {

	sensorPin=x;
	directionIn=y; // to be debated
}

void SetPin(int x) {

	sensorPin = x;
}

int GetPin() {
	return sensorPin;
}

void SetDirectionIn(bool x) {

	directionIn = x;
}

int GetDirectionIn() {
	return directionIn;
}

//virtual int GetStatus();
//virtual void Run();
void SetConstraints(int Pin, bool Direction) {
	sensorPin = Pin;
	directionIn = Direction;
}

Sensor::~Sensor() {
	// TODO Auto-generated destructor stub
}

