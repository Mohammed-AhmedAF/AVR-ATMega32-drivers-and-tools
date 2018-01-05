/*
 * main.c
 *
 *  Created on: 5 Jan 2018
 *      Author: mohamed
 * This code will turn on two seven-segments displays
 * and make them display numbers from 0 to 99
 */

#include "dio.h"
#include <util/delay.h>

#define SetBit(Reg,bit) Reg |=(1<<bit)
#define ClearBit(Reg, bit) Reg &=~(1<<bit)
#define GetBit(Reg,bit) ((Reg>>bit)&1)

u8 num[10] = {0b10100000,0b10101111,0b11000100,0b10000110,0b10001011,0b10010010,0b10010000,0b10100111,0b10000000,
0b10000010};

void main(void) {
	u8 i, b,d;
	DDRA = 0xff;
	DDRB = 0xff;
	PORTA = 0x00;
	PORTB = 0x00;
	DDRC = 0xff;
	PORTC = 0x00;
	DDRD = 0xff;
	PORTD = 0x00;

	while(1) {
		SetBit(PORTA,0);
		SetBit(PORTC,0);
		for(i = 99; i >= 0; i--) {
		_delay_ms(250);
		d = i%10;
		b = (i-i%10)/10;
		PORTB = num[b];
		PORTD = num[d];
		_delay_ms(250);
		}
	}
}
