/*
 * spi.h
 *
 * Created: 5/18/2019 1:05:10 PM
 *  Author: swain
 */ 


#ifndef SPI_H_
#define SPI_H_

#define PIN_SCK    PINB5
#define PIN_MOSI   PINB3
#define PIN_SS0    PINC3
#define PIN_SS1    PIND7

//#define MAX7219_LOAD_OFF_1(num)          PORTB |= (1<<(PIN_SS ## num))
//#define MAX7219_LOAD_ON_1(num)          PORTB &=~ (1<<(PIN_SS ## num))

#define MAX7219_LOAD_OFF_1(num)          PORTC |= (1<<(PIN_SS0))
#define MAX7219_LOAD_ON_1(num)          PORTC &=~ (1<<(PIN_SS0))

#define MAX7219_LOAD_OFF_2(num)          PORTD |= (1<<(PIN_SS1))
#define MAX7219_LOAD_ON_2(num)          PORTD &=~ (1<<(PIN_SS1))

#include <avr/io.h>

void spi_init() {
	// SCK MOSI CS/LOAD/SS
	DDRB |= (1 << PIN_SCK) | (1 << PIN_MOSI) ;
	DDRC |= (1 << PIN_SS0);
	DDRD |= (1 << PIN_SS1);

	// SPI Enable, Master mode
	SPCR |= (1 << SPE) | (1 << MSTR)| (1<<SPR1);
}

void spiSendByte (char databyte)
{
	// Copy data into the SPI data register
	SPDR = databyte;
	// Wait until transfer is complete
	while (!(SPSR & (1 << SPIF)));
}



#endif /* SPI_H_ */