#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "Password_interface.h"
#include <util/delay.h>
void main(void) {
	EEPROM_vidInit();
	EEPROM_u8WriteByte(PASSWORD_SAVED_PASSWORD_FLAG_LOCATION,0);
	_delay_ms(500);
	EEPROM_u8WriteByte(PASSWORD_BLOCKED_FLAG_LOCATION,PASSWORD_NOT_BLOCKED);
}
