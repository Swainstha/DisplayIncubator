
#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define OFF 0
#define ON 1

#define TS_LOW_LED 0
#define TS_HIGH_LED 1
#define RH_LOW_LED 2
#define RH_HIGH_LED 3
#define TA_LOW_LED 4
#define TA_HIGH_LED 5
#define INCUBATOR_LED 6
#define PHOTOTHERAPY_LED 7 
#define HUMIDITY_1_LED 8
#define HUMIDITY_2_LED 9
#define HUMIDITY_3_LED 10

class led {
	public:
	void led_init();
	void led_do(int led_num, int state);
};

#endif /* PINS_H_ */