#include <stdio.h>
#include <mraa.h>
#include <math.h>           // for the log function


#define WATER_ADC_PIN    3    // ADC pin is 3

int main(void)
{
    mraa_gpip_context   adcPin;           // used as AIO context

    /* Step1: Initialize the mraa */
    mraa_init();

    /* Step2: Initlaize the ADC pin */
    adcPin = mraa_gpio_init(WATER_ADC_PIN);
    mraa_gpio_dir(adcPin, MRAA_GPIO_OUT); // setting the stream direction

    for(int i=0;i<=10;i++){
    adcValue = mraa_gpio_write(adcPin, i%2);
    if(i%2==1)
    sleep(0.1);
    else
    sleep(1);

    }
    return 0;
}
