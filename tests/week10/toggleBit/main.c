/*
Just a very small project to test toggling a bit using macro
*/
#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"
#include <util/delay.h>

void main(void) {
	Dio_vidSetPortDirection(DIO_PORTA,0b00000001);
	
	while (1) {
		Toggle_Bit(PORTA,0);
		_delay_ms(1000);
	}
}
