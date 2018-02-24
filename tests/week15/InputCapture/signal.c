/*Signal for frequency meter*/

#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include <util/delay.h>
void main(void) {
	DIO_vidSetPinDirection(DIO_PORTA,DIN3,1);
	while(1) {
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,1);
	_delay_ms(10);
	DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,0);
	_delay_ms(20);
	
	}
}
