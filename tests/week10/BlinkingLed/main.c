#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include <util/delay.h>
void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b00000001);
	
	while(1) {
		Dio_vidSetPinValue(DIO_PORTA,0,1);
		_delay_ms(100);
		Dio_vidSetPinValue(DIO_PORTA,0,0);
		_delay_ms(100);
	}
}
