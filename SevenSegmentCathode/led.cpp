#include "led.h"
#include "pins.h"
#include "header.h"
#include <avr/io.h>

#define DDR(x) (*(&x - 1))      /* address of data direction register of port x */

void led::led_init() {
	DDR(TS_HIGH_PORT) |= (1 << TS_HIGH_PIN);
	DDR(TS_LOW_PORT) |= (1 << TS_LOW_PIN);
	DDR(TA_HIGH_PORT) |= (1 << TA_HIGH_PIN);
	DDR(TA_LOW_PORT) |= (1 << TA_LOW_PIN);
	DDR(HUMIDITY_1_PORT) |= (1 << HUMIDITY_1_PIN);
	DDR(HUMIDITY_2_PORT) |= (1 << HUMIDITY_2_PIN);
	DDR(HUMIDITY_3_PORT) |= (1 << HUMIDITY_3_PIN);
	DDR(HUMIDITY_LOW_PORT) |= (1 << HUMIDITY_LOW_PIN);
	DDR(HUMIDITY_HIGH_PORT) |= (1 << HUMIDITY_HIGH_PIN);
	DDR(INCUBATOR_PORT) |= (1 << INCUBATOR_PIN);
	DDR(PHOTOTHERAPHY_PORT) |= (1 << PHOTOTHERAPHY_PIN);
}


void led::led_do(int led_num, int state) {
	switch(led_num) {
		case TS_HIGH_LED:
		REGISTER_LED(TS_HIGH_PORT, TS_HIGH_PIN, state);
		break;
		case TS_LOW_LED:
		REGISTER_LED(TS_LOW_PORT, TS_LOW_PIN, state);
		break;
		case RH_HIGH_LED:
		REGISTER_LED(HUMIDITY_HIGH_PORT, HUMIDITY_HIGH_PIN, state);
		break;
		case RH_LOW_LED:
		REGISTER_LED(HUMIDITY_LOW_PORT, HUMIDITY_LOW_PIN, state);
		break;
		case TA_HIGH_LED:
		REGISTER_LED(TA_HIGH_PORT, TA_HIGH_PIN, state);
		break;
		case TA_LOW_LED:
		REGISTER_LED(TA_LOW_PORT, TA_LOW_PIN, state);
		break;
		case INCUBATOR_LED:
		REGISTER_LED(INCUBATOR_PORT, INCUBATOR_PIN, state);
		break;
		case PHOTOTHERAPY_LED:
		REGISTER_LED(PHOTOTHERAPHY_PORT, PHOTOTHERAPHY_PIN, state);
		break;
		case HUMIDITY_1_LED:
		REGISTER_LED(HUMIDITY_1_PORT, HUMIDITY_1_PIN, state);
		break;
		case HUMIDITY_2_LED:
		REGISTER_LED(HUMIDITY_2_PORT, HUMIDITY_2_PIN, state);
		break;
		case HUMIDITY_3_LED:
		REGISTER_LED(HUMIDITY_3_PORT, HUMIDITY_3_PIN, state);
		break;
		
	}
}