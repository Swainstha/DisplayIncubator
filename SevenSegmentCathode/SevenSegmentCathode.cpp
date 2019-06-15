#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "max7219.h"
#include "uart.h"
#include "led.h"

volatile uint8_t receivedByte = 0;
volatile uint8_t previous_receivedByte = 0;
uint8_t data[9] = {35,80,35,50,53,6,34,97,28};
int i = 0;
bool startSaving = false;
volatile bool received = false;
volatile bool display = false;
led led1;


int main(void)
{
	sei();
	led1.led_init();
	uart_init();
	
	max7219 max1;
	max7219 max2;
	max1.MAX7219_set(0,4,4);
	
	_delay_ms(10);
	max2.MAX7219_set(1, 4, 4);
	_delay_ms(10);
	max1.MAX7219_init();
	_delay_ms(10);
	max2.MAX7219_init();
	_delay_ms(10);
	max1.MAX7219_clearDisplay();
	_delay_ms(30);
	max2.MAX7219_clearDisplay();
	_delay_ms(30);
	max1.MAX7219_writeData(8, data[0] / 10);
	max1.MAX7219_writeData(6, (data[0] % 10) | 0b10000000);
	
	max1.MAX7219_writeData(2, data[1] / 10);
	
	max1.MAX7219_writeData(7, data[2] / 10);
	max1.MAX7219_writeData(5, (data[2] % 10) | 0b10000000);
		
	max1.MAX7219_writeData(1, data[3] / 10);
	

	max2.MAX7219_writeData(1, data[4] / 10);
	
	max2.MAX7219_writeData(5, data[4] % 10);
	
	max2.MAX7219_writeData(4, data[5] / 10);
	max2.MAX7219_writeData(6, data[5] % 10);
	max2.MAX7219_writeData(8, data[6] / 10);
	max2.MAX7219_writeData(2, data[6] % 10);
	
     


	/*led1.led_do(0, ((data[7] & (1<<0)) != 0)?true:false);
	led1.led_do(1, ((data[7] & (1<<1)) != 0)?true:false);
	led1.led_do(2, ((data[7] & (1<<2)) != 0)?true:false);
	led1.led_do(3, ((data[7] & (1<<3)) != 0)?true:false);
	led1.led_do(4, ((data[7] & (1<<4)) != 0)?true:false);
	led1.led_do(5, ((data[7] & (1<<5)) != 0)?true:false);
	led1.led_do(6, ((data[7] & (1<<6)) != 0)?true:false);
	led1.led_do(7, ((data[7] & (1<<7)) != 0)?true:false);
	led1.led_do(8, ((data[8] & (1<<0)) != 0)?true:false);
	led1.led_do(9, ((data[8] & (1<<1)) != 0)?true:false);
	led1.led_do(10, ((data[8] & (1<<2)) != 0)?true:false);
	led1.led_do(11, ((data[8] & (1<<3)) != 0)?true:false);
	*/
	
	
	while(1)
	{
		if(received && display) {
			
			//max1.MAX7219_clearDisplay();
			//max2.MAX7219_clearDisplay();
			//_delay_ms(50);
			
			max1.MAX7219_writeData(8, data[0] / 10);
			max1.MAX7219_writeData(6, (data[0] % 10) | 0b10000000);
			
			max1.MAX7219_writeData(2, data[1] / 10);
			
			max1.MAX7219_writeData(7, data[2] / 10);
			max1.MAX7219_writeData(5, (data[2] % 10) | 0b10000000);
			
			max1.MAX7219_writeData(1, data[3] / 10);
			
			max2.MAX7219_writeData(8, 13 / 10);
			
			
			max2.MAX7219_writeData(1, data[4] / 10);
			
			max2.MAX7219_writeData(5, data[4] % 10);
			
			max2.MAX7219_writeData(4, data[5] / 10);
			max2.MAX7219_writeData(6, data[5] % 10);
			max2.MAX7219_writeData(8, data[6] / 10);
			max2.MAX7219_writeData(2, data[6] % 10);
			display = false;
			
			//_delay_ms(2000);					
		}	
					
		if(receivedByte == 255 && received) {
			if(previous_receivedByte == 255) {
				startSaving = true;
				previous_receivedByte = 0;
				i = 0;
			} else 
			{
				previous_receivedByte = receivedByte;
				receivedByte= 0;
			}			
			received = false;
			
		} else if(startSaving && received) {
			data[i] = receivedByte;
			received = false;
			i++;
			
			if(i >= 9) {
			
				i = 0;
				receivedByte = previous_receivedByte = 0;
				startSaving = false;
				display = true;
			}
		} 
	}
}

			
ISR(USART_RX_vect) {
	receivedByte = UDR0;
	received = true;
	//display = true;
}
