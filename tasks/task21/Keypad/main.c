#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "Services_interface.h"
#include <util/delay.h>

u8 u8rowsPorts[4] = {DIO_PORTC,DIO_PORTC,DIO_PORTC,DIO_PORTC};
u8 u8rowsPins[4] = {0,1,2,3};
u8 u8colsPorts[4] = {DIO_PORTC,DIO_PORTC,DIO_PORTC,DIO_PORTC};
u8 u8colsPins[4] = {4,5,6,7};

void main(void) {
	KEYPAD_vidInit_1(u8rowsPorts,u8rowsPins,u8colsPorts,u8colsPins);
	LCD_vidInit();

	while(1) {
		Services_vidWriteCharacter();
	}
}
