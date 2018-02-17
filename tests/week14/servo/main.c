#include "DIO_interface.h"
#include <util/delay.h>
#include "Std_Types.h"
#include "Macros.h"

void main(void) {
	DIO_vidSetPinDirection(DIO_PORTA,0,1);
	while(1) {
		DIO_vidSetPinValue(DIO_PORTA,0,1);
		_delay_us(1000);
		DIO_vidSetPinValue(DIO_PORTA,0,0);
		_delay_us(19000);

	}
}
