#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "EEPROM_interface.h"
#include "TWI_interface.h"

#define MESSAGE_SIZE_LOCATION 200
u8 u8Flag = 0;
u8 u8Byte;
u8 i = 0;
u8 u8MessageSize = 0;
void main(void) {
	EEPROM_vidInit();
	LCD_vidInit();
	
	EEPROM_u8ReadByte(MESSAGE_SIZE_LOCATION,&u8MessageSize);
	do {
		u8Flag = EEPROM_u8ReadByte(i,&u8Byte);
		LCD_vidWriteCharacter(u8Byte);
		i++;
	}
	while(i != u8MessageSize);
}
