#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include <avr/io.h>
#include <util/delay.h>
void main(void) {
	DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN0,STD_HIGH);
	DIO_vidSetPinValue(DIO_PORTB,DIO_PIN0,STD_HIGH);
}

