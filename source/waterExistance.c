#include <stdio.h>
#include <mraa.h>
#include <math.h>
#include <mraa/gpio.h>         // for the log function

const int B  = 4275;         // B value for thermistor
const int R0 = 100;          // R0 is 100k ohms

#define WATER_ADC_PIN    4    // ADC pin is 4

int main(void)
{
    mraa_gpio_context   adcPin;           // used as AIO context
    float              adcValue;         // Used in calculations

    /* Step1: Initialize the mraa */
    mraa_init();

    /* Step2: Initlaize the ADC pin */
    adcPin = mraa_gpio_init(WATER_ADC_PIN); // ai gives level
                                            // digital gives if there is water or not

    for(int i=0;i<=10;i++){



    /* Step3: Read the ADC value */
    adcValue = mraa_gpio_read(adcPin);
    
    /* Step4: Apply the transformation */

    /* Step5: Print the temperature */
    printf ("The humidity is %0.2f degree Celcius \n", adcValue);
    sleep(1);

    }
    return 0;
}

