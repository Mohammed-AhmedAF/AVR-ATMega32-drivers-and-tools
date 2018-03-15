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

u8 u8Repeat,u8MatchFlag;
extern u8 u8IDSize;
extern u8 u8PasswordSize;
extern u8 u8PasswordStart;

int main(void) {
	LCD_vidInit();
	KEYPAD_vidInit();	
	EEPROM_vidInit();

	Password_vidAskID();
	Password_vidAskPassword();
	Password_vidReenterPassword();
	do {
	u8MatchFlag = Password_vidCheckPasswordMatch(u8PasswordSize);
	}while(u8MatchFlag == 0);

	Password_vidSaveID(u8IDSize);
	Password_vidSavePassword(u8PasswordStart,u8PasswordSize);
	_delay_ms(2000);
	Password_vidRetreiveID(u8IDSize);
	//Password_vidReadPassword(u8PasswordStart,u8PasswordSize);
	while(1);
}
