
#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL

#define baud 9600UL
#define baud_pre ((F_CPU/(baud*16))-1)

#include <avr/io.h>
#include <avr/interrupt.h>

void uart_init() {
	
	UBRR0H=(baud_pre>>8);
	UBRR0L=baud_pre;
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0)|(1<<RXCIE0);
	UCSR0C |= (1 <<UCSZ00) | (1 << UCSZ01);
}


#endif /* UART_H_ */