/*
* PCF8574_program.c
*
* Created: 12/2/2021 6:01:37 AM
*  Author: Mohammed
*/

#include "Macros.h"
#include "Std_Types.h"
#include "TWI_interface.h"
#include "PCF8574_config.h"
#include "PCF8574_interface.h"

void PCF8574_vidWriteByte(u8 u8Byte)
{

	TWI_vidSendStart();
	TWI_vidSendByte(_PCF8574_ADDRESS);
	TWI_vidSendByte(u8Byte);
	TWI_vidSendStop();
}