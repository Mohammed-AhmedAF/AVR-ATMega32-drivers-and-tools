/*
 * Author: Mohamed Ahmed Abd Al Fattah
 * Purpose: Graphical LCD driver
 *
 */

/* 
 * CS1, CS2 are chip selects, those are used
 * to select one of two chips controlling the
 * two segments of the display. Different GLCD modules differ in
 * the application of these two pins.
 *
 *
 * RS: Register Select, Data/Instruction select.
 */

#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "GLCD_interface.h"
#include "util/delay.h"


void GLCD_vidInit(void) {
	/*Setting pin direction*/
	DIO_vidSetPinDirection(GLCD_D0_PORT,GLCD_D0_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D1_PORT,GLCD_D1_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D2_PORT,GLCD_D2_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D3_PORT,GLCD_D3_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D4_PORT,GLCD_D4_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D5_PORT,GLCD_D5_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D6_PORT,GLCD_D6_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D7_PORT,GLCD_D7_PIN,DIO_OUTPUT);

	/*Setting pin direction for command pits*/
	DIO_vidSetPinDirection(GLCD_PSB_PORT,GLCD_PSB_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_CS2_PORT,GLCD_CS2_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_RST_PORT,GLCD_RST_PIN,DIO_OUTPUT);

	/*Setting direction for pins RS,RW,EN*/
	DIO_vidSetPinDirection(GLCD_RS_PORT,GLCD_RS_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_RW_PORT,GLCD_RW_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_EN_PORT,GLCD_EN_PIN,DIO_OUTPUT);


	_delay_ms(20);

	DIO_vidSetPinValue(GLCD_RST_PORT,GLCD_RST_PIN,STD_LOW);
	_delay_ms(120);
	DIO_vidSetPinValue(GLCD_RST_PORT,GLCD_RST_PIN,STD_HIGH);
	_delay_ms(50);

	_delay_ms(100);
	GLCD_vidSendCommand(GLCD_FUNCTIONSET); /*Function set*/
	_delay_ms(120);
	GLCD_vidSendCommand(GLCD_DISPLAYON);  /*Display on/off control*/
	_delay_ms(50);
	GLCD_vidSendCommand(GLCD_FUNCTIONSET); /*Function set*/
	_delay_ms(120);
	GLCD_vidSendCommand(GLCD_CLEARSCREEN); /*Clear*/
	_delay_ms(20);
	GLCD_vidSendCommand(GLCD_ENTRYMODE); /*Entry mode*/
	_delay_ms(120);

}

void GLCD_vidSendCommand(u8 u8CommandCpy) {
	DIO_vidSetPinValue(GLCD_RS_PORT,GLCD_RS_PIN,STD_LOW);
	DIO_vidSetPinValue(GLCD_RW_PORT,GLCD_RW_PIN,STD_LOW);

	DIO_vidSetPinValue(GLCD_D0_PORT,GLCD_D0_PIN,GET_BIT(u8CommandCpy,0));
	DIO_vidSetPinValue(GLCD_D1_PORT,GLCD_D2_PIN,GET_BIT(u8CommandCpy,1));
	DIO_vidSetPinValue(GLCD_D2_PORT,GLCD_D3_PIN,GET_BIT(u8CommandCpy,2));
	DIO_vidSetPinValue(GLCD_D3_PORT,GLCD_D3_PIN,GET_BIT(u8CommandCpy,3));
	DIO_vidSetPinValue(GLCD_D4_PORT,GLCD_D4_PIN,GET_BIT(u8CommandCpy,4));
	DIO_vidSetPinValue(GLCD_D5_PORT,GLCD_D5_PIN,GET_BIT(u8CommandCpy,5));
	DIO_vidSetPinValue(GLCD_D6_PORT,GLCD_D6_PIN,GET_BIT(u8CommandCpy,6));
	DIO_vidSetPinValue(GLCD_D7_PORT,GLCD_D7_PIN,GET_BIT(u8CommandCpy,7));


	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PIN,STD_HIGH);
	_delay_ms(120);
	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PIN,STD_LOW);
	_delay_ms(120);
}

void GLCD_vidWrite(u8 u8Data) {
	DIO_vidSetPinValue(GLCD_RS_PORT,GLCD_RS_PIN,STD_HIGH);
	DIO_vidSetPinValue(GLCD_RW_PORT,GLCD_RW_PIN,STD_LOW);
	
	/*Putting data pits into corresponding pins*/
	DIO_vidSetPinValue(GLCD_D0_PORT,GLCD_D0_PIN,GET_BIT(u8Data,0));
	DIO_vidSetPinValue(GLCD_D1_PORT,GLCD_D2_PIN,GET_BIT(u8Data,1));
	DIO_vidSetPinValue(GLCD_D2_PORT,GLCD_D3_PIN,GET_BIT(u8Data,2));
	DIO_vidSetPinValue(GLCD_D3_PORT,GLCD_D3_PIN,GET_BIT(u8Data,3));
	DIO_vidSetPinValue(GLCD_D4_PORT,GLCD_D4_PIN,GET_BIT(u8Data,4));
	DIO_vidSetPinValue(GLCD_D5_PORT,GLCD_D5_PIN,GET_BIT(u8Data,5));
	DIO_vidSetPinValue(GLCD_D6_PORT,GLCD_D6_PIN,GET_BIT(u8Data,6));
	DIO_vidSetPinValue(GLCD_D7_PORT,GLCD_D7_PIN,GET_BIT(u8Data,7));

	
	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PIN,STD_HIGH);
	_delay_ms(120);
	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PIN,STD_LOW);
	_delay_ms(120);

}

void GLCD_vidEnableGraphics(void) {

	GLCD_vidSendCommand(0x20);  
	_delay_ms(1);
	GLCD_vidSendCommand(0x24); 
	_delay_ms(1);
	GLCD_vidSendCommand(0x26);
	_delay_ms(1);
	_delay_ms(5);
}


void GLCD_vidDisableGraphics(void) {
	GLCD_vidSendCommand(0x20);
	_delay_ms(5);
}
