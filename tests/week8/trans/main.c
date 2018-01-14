#include "dio.h"
#include <util/delay.h>
void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b00000011);
	Dio_vidSetPortValue(DIO_PORTA,0b00000010);
	while(1) {
		Dio_vidSetPinValue(DIO_PORTA,0,1);
		Dio_vidSetPinValue(DIO_PORTA,1,0);
		_delay_ms(1000);
		Dio_vidSetPinValue(DIO_PORTA,0,0);
		Dio_vidSetPinValue(DIO_PORTA,1,1);
		_delay_ms(1000);
	}
}
