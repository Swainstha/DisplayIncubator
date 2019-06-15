/*
 * max7219.h
 *
 * Created: 5/18/2019 1:08:31 PM
 *  Author: swain
 */ 


#ifndef MAX7219_H_
#define MAX7219_H_

#define ON 1
#define OFF 0
#define MAX7219_MODE_DECODE       0x09
#define MAX7219_MODE_INTENSITY    0x0A
#define MAX7219_MODE_SCAN_LIMIT   0x0B
#define MAX7219_MODE_POWER        0x0C
#define MAX7219_MODE_TEST         0x0F
#define MAX7219_MODE_NOOP         0x00

// I only have 3 digits, no point having the
// rest. You could use more though.
#define MAX7219_DIGIT0            0x01
#define MAX7219_DIGIT1            0x02
#define MAX7219_DIGIT2            0x03
#define MAX7219_DIGIT3            0x04

#define MAX7219_CHAR_BLANK        0xF
#define MAX7219_CHAR_NEGATIVE     0xA



class max7219 {
		private:
			int num;
			int digits1;
			int digits2;
		public:
			void MAX7219_set(int numm, int ii, int jj);
			void MAX7219_init();
			void MAX7219_writeData(char data_register, char data);
			void MAX7219_clearDisplay();
			void MAX7219_displayNumber(volatile long number);
			
	};



#endif /* MAX7219_H_ */