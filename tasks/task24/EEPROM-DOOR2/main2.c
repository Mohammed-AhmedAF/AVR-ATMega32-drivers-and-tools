#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"


u8 u8Byte;
u8 i;
void main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();
	EEPROM_vidInit();

	for (i = 0; i < 5; i++) {
		EEPROM_u8ReadByte(i,&u8Byte);
		LCD_vidWriteCharacter(u8Byte);
	}
}
