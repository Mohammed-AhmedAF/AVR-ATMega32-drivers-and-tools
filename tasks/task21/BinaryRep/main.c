#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "LCD_interface.h"
#include "Services_interface.h"
#include <util/delay.h>

void main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();
	DIO_vidSetPortDirection(DIO_PORTB,0b11111111);

	while(1) {
		Services_vidWriteCharacter();
		DIO_vidSetPortValue(DIO_PORTB,u8keyPressed-0x30);
	}
}

