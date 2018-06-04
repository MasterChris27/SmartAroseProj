#include <stdio.h>
#include <mraa.h>
#include <math.h>           // for the log function

const int B = 4275;         // B value for thermistor
const int R0 = 100;          // R0 is 100k ohms

#define TEMP_ADC_PIN    1    // ADC pin is 1
#define HUMIDITY_ADC_PIN    0    // ADC pin is 0

abstract class Sensor {

protected:
	int sensorPin;
    int sensorDirection;


public:

    Sensor();

    int  GetValue();
    void Run();
    void SetConstraints(int Pin , int Direction) {
    	sensorPin= Pin;
    	sensorDirection = Direction;
    };

};

int Pin,Direction;



SetConstraints()
GetStatus()
GetValue()


class SensorAnalog : Sensor public {

protected:

	mraa_aio_context m_aio;

	float min_raw_value;
	float max_raw_value;
	float sensor_range;

	float min_scaled_value;
	float max_scaled_value;
	float measure_range;

	float measured_value;

public:

//constructeur
	sensor() {
		min_scaled_value = min_raw_value;
		max_scaled_value = max_raw_value;
	}

	void calibrate (float min, float max) {
		min_scaled_value = min;
		max_scaled_value = max;
	}
	float scaleMeasuredValue {
		scaled_measured_value = (measured_value - min_raw_value)/ sensor_range * measure_range + min_scaled value;

	}

	float getValue() {

	}

};





class SensorDigital : Sensor public {

protected:

	mraa_aio_context m_aio;

	float min_raw_value;
	float max_raw_value;
	float sensor_range;

	float min_scaled_value;
	float max_scaled_value;
	float measure_range;

	float measured_value;

public:

//constructeur
	sensor() {
		min_scaled_value = min_raw_value;
		max_scaled_value = max_raw_value;
	}

	void calibrate (float min, float max) {
		min_scaled_value = min;
		max_scaled_value = max;
	}
	float scaleMeasuredValue {
		scaled_measured_value = (measured_value - min_raw_value)/ sensor_range * measure_range + min_scaled value;

	}

	float getValue() {

	}

};






class Actioneur {

};

int main(void) {
	mraa_aio_context adcPin;           // used as AIO context
	float adcValue;         // ADC value read into this variable
	float R, temperature;   // Used in calculations

	/* Step1: Initialize the mraa */
	mraa_init();

	/* Step2: Initlaize the ADC pin */
	adcPin = mraa_aio_init(TEMP_ADC_PIN);

	/* Step3: Read the ADC value */
	adcValue = mraa_aio_read(adcPin);

	/* Step4: Apply the transformation */
	R = 1023.0 / ((float) adcValue) - 1.0;    // Promote to float
	R = 100000.0 * R;

	temperature = 1.0 / (log(R / 100000.0) / B + 1 / 298.15) - 273.15;

	/* Step5: Print the temperature */
	printf("The temperature is %0.2f degree Celcius\n", temperature);

	return 0;
}

