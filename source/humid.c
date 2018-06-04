#include <stdio.h>
#include <mraa.h>
#include <math.h>           // for the log function

const int B  = 4275;         // B value for thermistor
const int R0 = 100;          // R0 is 100k ohms

#define TEMP_ADC_PIN    1    // ADC pin is 0

int main(void)
{
    mraa_aio_context   adcPin;           // used as AIO context
    float              adcValue;         // ADC value read into this variable
    float              R, temperature;   // Used in calculations

    /* Step1: Initialize the mraa */
    mraa_init();

    /* Step2: Initlaize the ADC pin */
    adcPin = mraa_aio_init(TEMP_ADC_PIN);

for(int i=0;i<20;i++){
    adcValue = mraa_aio_read(adcPin);
    printf ("The humidity is %0.2f idk what this is\n", adcValue);
sleep(2);
}
    return 0;
}

