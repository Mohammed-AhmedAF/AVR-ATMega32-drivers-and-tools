#include "dio.h"
#include <util/delay.h>

void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b00000001);
	while(1) {
		Dio_vidSetPortValue(DIO_PORTA,0b00000001);
		_delay_ms(500);
		Dio_vidSetPortValue(DIO_PORTA,0b00000000);
		_delay_ms(500);
	}
}
