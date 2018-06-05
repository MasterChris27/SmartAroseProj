/*
 * SmartArose.cpp
 *
 *  Created on: 30 mai 2018
 *      Author: boza
 */
#define EXISTS_WATER 0.0
#define HUMID_SOIL 350.0  // idk what this is
#define TEMPERATURE_LIMIT 5 // degrees celcius
#define TIME_WAIT_BUTTON 10 // seconds
#define BTN_PUSHED 1
#define HUMIDITY_LIMIT 20 // not defined yet
#define WET_PERIOD 4
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

		if( btn.GetStatus()== BTN_PUSHED ){
			printf("\n button status is %d and restrictor is %d\n",btn.GetStatus(),wetingRestrictor);
		//	btn.SetStatus(0);
			if(wetingRestrictor==0) {

				if(wT.GetWaterLevel()==EXISTS_WATER){
					printf("\n button is pushed and we are weting\n");
					wT.Arose(2);
					wetingRestrictor=WET_PERIOD;
				}else{
					printf("\n button is pushed but there is no water in the tank\n");
					//continue;
				}

			}else{
				printf("\n button was pushed but we recently wet \n");
				//btnRestrictor--;
				//continue;
			}
		}



		if(wT.GetWaterLevel()==EXISTS_WATER) { // if there is water in the tank

			printf("\n there is water in the tank\n");

			if(plant.GetTemp()>=TEMPERATURE_LIMIT){ // temperature is good


				printf("\n temperature is good \n");

				// modify or add actual water level for the plant here
				if (plant.GetHumidity()>=HUMID_SOIL){

					//wetingRestrictor--; // if we don't need to wet then we decrease the time
					printf("\n humidity is good \n\n No need to arose ! id res %d\n",wetingRestrictor);
					break;
				}else{
					if(wetingRestrictor<=0){
						printf("\n humidity %d is not good and we are weting \n",plant.GetHumidity());
						wT.Arose(3);
						printf("\n We arosed \n");
						wetingRestrictor=WET_PERIOD;
					}else{
						printf("\n Humidity %d not good but we just wet, restrictor is %d\n",plant.GetHumidity(),wetingRestrictor);
						wetingRestrictor--;
					}
				}

			}else{			//case it is too cold

				printf("\n temperature is low\n");
				while(plant.GetTemp()<TEMPERATURE_LIMIT){
					buzz.Run(1);
					led.Run(1);
					sleep(2);
				}
			}
		}else{
		//	wetingRestrictor=0;
			printf("\n there is no water in the tank water\n");
			while(wT.GetWaterLevel()!=EXISTS_WATER){  // we signal all the time that there is no water
				printf("\n Please add water in the tank \n");

				buzz.Run(1); // we signall
				led.Run(1);
				sleep(3);
			}

			printf("\n The plant thanks you for adding water\n");

		}


		sleep(3); // wait before we loop
	}
}

SmartArose::~SmartArose() {
	// TODO Auto-generated destructor stub
}

