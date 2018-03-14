#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "Password_interface.h"
#include "Services_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include <util/delay.h>

extern u8 u8IDSize;
int main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();	
	
	Password_vidAskID();
	Password_vidShowID(u8IDSize);
	Password_vidSaveID(u8IDSize);
	_delay_ms(2000);
	Password_vidRetreiveID(u8IDSize);
	while(1);
}
