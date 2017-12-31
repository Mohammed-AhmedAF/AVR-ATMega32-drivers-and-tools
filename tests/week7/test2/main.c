#include "dio.h"
#include <util/delay.h>

void main(void) {
	DDRA = 0b11111111;
	PORTA = 0b10000000;	

	for (int i = 1; i < 10; i++) {
		_delay_ms(0.5*1000);
		PORTA = PORTA >> 1; 	
		_delay_ms(0.5*1000);
	}
}
