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


void IC74165_vidInitExtended(IC165_t * strctPtIC165Data) {
	DIO_vidSetPinDirection(strctPtIC165Data->u8CLKINH_Port,strctPtIC165Data->u8CLKINH_Pin,DIO_OUTPUT);
	DIO_vidSetPinDirection(strctPtIC165Data->u8SHLD_Port,strctPtIC165Data->u8SHLD_Pin,DIO_OUTPUT);
}

u8 IC74165_u8GetByte(void) {
	u8 u8Byte;
	DIO_vidSetPinValue(IC74165_CLKINH_PORT,IC74165_CLKINH_PIN,STD_HIGH);
	
	DIO_vidSetPinValue(IC74165_SHLD_PORT,IC74165_SHLD_PIN,STD_LOW);
	
	DIO_vidSetPinValue(IC74165_CLKINH_PORT,IC74165_CLKINH_PIN,STD_LOW);
	DIO_vidSetPinValue(IC74165_SHLD_PORT,IC74165_SHLD_PIN,STD_HIGH);
	
	u8Byte = SPI_u8ReceiveByte();
	
	return u8Byte;
}

u8 IC74165_u8GetByteExtended(IC165_t * strctPtIC165Data) {
	u8 u8Byte;
	DIO_vidSetPinValue(strctPtIC165Data->u8CLKINH_Port,strctPtIC165Data->u8CLKINH_Pin,STD_HIGH);
	
	DIO_vidSetPinValue(strctPtIC165Data->u8SHLD_Port,strctPtIC165Data->u8SHLD_Pin,STD_LOW);
	
	DIO_vidSetPinValue(strctPtIC165Data->u8CLKINH_Port,strctPtIC165Data->u8CLKINH_Pin,STD_LOW);
	DIO_vidSetPinValue(strctPtIC165Data->u8SHLD_Port,strctPtIC165Data->u8SHLD_Pin,STD_HIGH);
	
	u8Byte = SPI_u8ReceiveByte();
	return u8Byte;
}
