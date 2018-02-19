#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include <util/delay.h>

void main(void) {
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	while(1) {
		TOGGLE_BIT(PORTA,0);
		_delay_us(100000);
	}
}
