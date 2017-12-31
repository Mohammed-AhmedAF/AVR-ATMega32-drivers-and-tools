/*
 * main.c
 *
 *  Created on: 31 Dec 2017
 *      Author: mohamed
 */

#include "dio.h"
#include <util/delay.h>

u8 compute(void);
u8 p(u8);
u8 leds;
static u8 cycle = 1;

void main(void) {

	DDRA = 0b11111111;
	PORTA = 0b00000111;
	s32 i = 1;
	u8 flag = 0;
	while (1) {
		if (flag == 0){
		PORTA = compute();
		}
		else {
			PORTA = p(cycle) | PORTA;
		}
		for (i = 1; i < 9-cycle; i++) {
			_delay_ms(0.5*1000);
			if (flag == 0) {
				PORTA = PORTA << 1;
			}
			else {
				PORTA = PORTA >> 1;
			}
			_delay_ms(0.5*1000);
		}
		i = 1;
		flag = !flag;
		cycle++;
		if (cycle == 9)
		{
			cycle = 1;
		}
	}
}


u8 compute (void) {
	u8 pow = 1;
	for (u8 j = 0; j < cycle; j++) {
		pow *= 2;
	}
	if (cycle%2 == 1) {
		return pow-1;
	}

}

u8 p (u8 cycle) {
	u8 pow = 1;
	for (u8 j = 0; j < 8 -cycle;j++) {
		pow *=2;
	}
	return pow;
}
