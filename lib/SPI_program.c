/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * File: SPI driver
 */
#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_vidInitMaster(void) {

	DIO_vidSetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,DIO_OUTPUT); /*MOSI*/
	DIO_vidSetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,DIO_INPUT); /*MISO*/
	DIO_vidSetPinDirection(SPI_SCK_PORT,SPI_SCK_PIN,DIO_OUTPUT); /*SCK*/
	DIO_vidSetPinDirection(SPI_SS_PORT,SPI_SS_PIN,DIO_OUTPUT); /*SS*/
		
	/*SPI control*/
	
	SET_BIT(SPCR,6); 
	/*Enable master*/
	SET_BIT(SPCR,4);
	/*4 prescaler*/
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,0);

}

void SPI_vidInitSlave(void)
{
	DIO_vidSetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,DIO_OUTPUT); /*MOSI*/
	DIO_vidSetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,DIO_INPUT); /*MISO*/
	DIO_vidSetPinDirection(SPI_SCK_PORT,SPI_SCK_PIN,DIO_OUTPUT); /*SCK*/
	DIO_vidSetPinDirection(SPI_SS_PORT,SPI_SS_PIN,DIO_OUTPUT); /*SS*/
		
	/*SPI control*/
	
	SET_BIT(SPCR,6); 
	/*Enable master*/
	CLEAR_BIT(SPCR,4);
	/*4 prescaler*/
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);


}


void SPI_vidEnableSS(void) {
	DIO_vidSetPinValue(SPI_SS_PORT,SPI_SS_PIN,STD_LOW);
}

void SPI_vidDisableSS(void) {
	DIO_vidSetPinValue(SPI_SS_PORT,SPI_SS_PIN,STD_HIGH);
}

void SPI_vidTransferByte(u8 u8ByteCpy) {
	SPDR = u8ByteCpy;
	while(!(SPSR & (1<<7)));										/* wait here while SPIF flag set */
}


u8 SPI_u8ReceiveByte(void) {
	while(!(SPSR & (1<<7)));
	return SPDR;
}

void SPI_vidEnableInterrupt(void) {
	SET_BIT(SPCR,7);
}

void SPI_vidDisableInterrupt(void) {
	CLEAR_BIT(SPCR,7);
}
 Void test(void)
{
}
