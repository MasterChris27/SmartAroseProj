/*
 * SmartArose.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */
#define EXISTS_WATER 0.0
#define HUMID_SOIL 500.0  // idk what this is
#define TEMPERATURE_LIMIT 5 // degrees celcius
#define TIME_WAIT_BUTTON 5 // seconds
#define BTN_PUSHED 1
#define HUMIDITY_LIMIT 20 // not defined yet
#include "SmartArose.h"

SmartArose::SmartArose() { // mention the pins to wich are connected
	//can be changed in the SmartArose.h !

	 wT=WaterTank(valvePin,waterLevelPin);
	 plant=Plant(waterExistPin,tempPin,humidityPin);
	 btn= Button(buttonPin);
	 buzz=Buzzer(buzzerPin);
	 led = Led(ledPin);
}


//test the buzzer and the humidity


void SmartArose::Run(){

	while(1){

			btn.WaitCommand(TIME_WAIT_BUTTON);

			printf("\n Not waiting after the btn anymore \n");
			if((btn.GetStatus()) ==( BTN_PUSHED)){
				    printf("\n button is pushed and we are arosing\n");
					wT.Arose(2);
					continue;
				}

		if(wT.GetWaterLevel()!=EXISTS_WATER) { // if there is water

		    printf("\n there is no water \n");

			if(plant.GetTemp()>TEMPERATURE_LIMIT){


			    printf("\n temperature is good \n");



				// modify or add actual water level for the plant here
				if (plant.GetHumidity()>=HUMID_SOIL || plant.GetHumidity()==HUMIDITY_LIMIT){

				    printf("\n humidity is good \n");

					break;
				}else{

				    printf("\n humidity is not good \n");
					wT.Arose(5);

				    printf("\n we arosed \n");
				}

			}else{			//case it is too cold

			printf("\n temperature is low\n");
			buzz.Run(2);
			led.Run(5);
			}
		}else{
			printf("\n there is water\n");
		}


	}
}

SmartArose::~SmartArose() {
	// TODO Auto-generated destructor stub
}

