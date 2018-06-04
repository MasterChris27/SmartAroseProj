#include "grovepi.h"
using namespace GrovePi;

// sudo g++ -Wall grovepi.cpp grove_led_blink.cpp -o grove_led_blink.out -> without grovepicpp package installed
// sudo g++ -Wall -lgrovepicpp grove_led_blink.cpp -o grove_led_blink.out -> with grovepicpp package installed

int main()
{
	int LED_pin = 4; // Grove LED is connected to digital port D4 on the GrovePi

	try
	{
		initGrovePi(); // initialize communication w/ GrovePi
		pinMode(LED_pin, OUTPUT); // set the LED pin as OUTPUT on the GrovePi
		delay(1000); // wait 1 second

		printf("This example will blink a Grove LED connected to the GrovePi+ on the port labeled D4.\n");
		printf("If you're having trouble seeing the LED blink, be sure to check the LED connection and the port number.\n");
		printf("You may also try reversing the direction of the LED on the sensor.\n\n");
		printf("Connect the LED to the port label D4!\n");

		// do indefinitely
		while(true)
		{
			// 1 second the LED is HIGH -> ON
			digitalWrite(LED_pin, HIGH);
			printf("[pin %d][LED ON]\n", LED_pin);
			delay(1000);

			// and another second LED is LOW -> OFF
			digitalWrite(LED_pin, LOW);
			printf("[pin %d][LED OFF]\n", LED_pin);
			delay(1000);
		}
	}
	catch(I2CError &error)
	{
		printf(error.detail());

		return -1;
	}

	return 0;
}