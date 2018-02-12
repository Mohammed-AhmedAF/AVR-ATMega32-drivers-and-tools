#include "dio.h"
#include <util/delay.h>

void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b000000:A1);
	while(1) {
		Dio_vidSetPinValue(DIO_PORTA,0,0);
		_delay_ms(500);
		Dio_vidSetPinValue(DIO_PORTA,0,1);
		_delay_ms(500);
	}
}
