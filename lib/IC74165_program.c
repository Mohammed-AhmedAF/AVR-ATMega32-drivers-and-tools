/*
 * IC74165_program.c
 *
 * Created: 7/21/2019 8:32:19 AM
 */ 

#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "IC74165_interface.h"

void IC74165_vidInit(void) {
	DIO_vidSetPinDirection(IC74165_CLKINH_PORT,IC74165_CLKINH_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(IC74165_SHLD_PORT,IC74165_SHLD_PIN,DIO_OUTPUT);
}

u8 IC74165_u8GetByte(void) {
	u8 u8Data;
	DIO_vidSetPinValue(IC74165_CLKINH_PORT,IC74165_CLKINH_PIN,STD_HIGH);
	
	DIO_vidSetPinValue(IC74165_SHLD_PORT,IC74165_SHLD_PIN,STD_LOW);
	
	DIO_vidSetPinValue(IC74165_CLKINH_PORT,IC74165_CLKINH_PIN,STD_LOW);
	DIO_vidSetPinValue(IC74165_SHLD_PORT,IC74165_SHLD_PIN,STD_HIGH);
	
	u8Data = SPI_u8ReceiveByte();
	
	return u8Data;
}