/*
 * GLCD_program.c
 *
 *  Created: 5/20/2019 9:15:11 AM
 *  Author: Mohamed Ahmed Abd Al-Fattah
 *  Purpose: Graphical LCD driver, based on code from electronicwings.com
 */ 

#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "Font_Header.h"
#include <util/delay.h>
#include "GLCD_interface.h"


void GLCD_vidInit(void) {
	/*Configuring direction for data pins*/
	DIO_vidSetPinDirection(GLCD_D0_PORT,GLCD_D0_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D1_PORT,GLCD_D1_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D2_PORT,GLCD_D2_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D3_PORT,GLCD_D3_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D4_PORT,GLCD_D4_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D5_PORT,GLCD_D5_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D6_PORT,GLCD_D6_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_D7_PORT,GLCD_D7_PIN,DIO_OUTPUT);
	
	/*Configuring direction for control pins*/
	DIO_vidSetPinDirection(GLCD_RS_PORT,GLCD_RS_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_RW_PORT,GLCD_RW_PIN,DIO_OUTPUT);
	DIO_vidSetPinDirection(GLCD_EN_PORT,GLCD_EN_PIN,DIO_OUTPUT);
	
	/*Giving initialization commands*/
	DIO_vidSetPinValue(GLCD_CS1_PORT,GLCD_CS1_PIN,STD_HIGH);
	DIO_vidSetPinValue(GLCD_CS2_PORT,GLCD_CS2_PIN,STD_HIGH);
	DIO_vidSetPinValue(GLCD_RST_PORT,GLCD_RST_PIN,STD_HIGH);
	
	_delay_us(20);
	
	GLCD_vidSendCommand(0x3E);
	GLCD_vidSendCommand(0x40);
	GLCD_vidSendCommand(0xB8);
	GLCD_vidSendCommand(0xC0);
	GLCD_vidSendCommand(0x3F);
}

void GLCD_vidSendCommand(u8 u8CommandCpy) {
	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PORT,STD_HIGH);
	DIO_vidSetPinValue(GLCD_RW_PORT,GLCD_RW_PIN,STD_LOW);
	DIO_vidSetPinValue(GLCD_RS_PORT,GLCD_RS_PIN,STD_LOW);
	
	/*Filling in the command to be sent*/
	DIO_vidSetPinValue(GLCD_D0_PORT,GLCD_D0_PIN,GET_BIT(u8CommandCpy,0));
	DIO_vidSetPinValue(GLCD_D1_PORT,GLCD_D1_PIN,GET_BIT(u8CommandCpy,1));
	DIO_vidSetPinValue(GLCD_D2_PORT,GLCD_D2_PIN,GET_BIT(u8CommandCpy,2));
	DIO_vidSetPinValue(GLCD_D3_PORT,GLCD_D3_PIN,GET_BIT(u8CommandCpy,3));
	DIO_vidSetPinValue(GLCD_D4_PORT,GLCD_D4_PIN,GET_BIT(u8CommandCpy,4));
	DIO_vidSetPinValue(GLCD_D5_PORT,GLCD_D5_PIN,GET_BIT(u8CommandCpy,5));
	DIO_vidSetPinValue(GLCD_D6_PORT,GLCD_D6_PIN,GET_BIT(u8CommandCpy,6));
	DIO_vidSetPinValue(GLCD_D7_PORT,GLCD_D7_PIN,GET_BIT(u8CommandCpy,7));
	
	_delay_ms(5);
	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PIN,STD_LOW);
	_delay_us(5);	
}

void GLCD_vidWriteCharacter(u8 u8CharacterCpy) {
	DIO_vidSetPinValue(GLCD_RS_PORT,GLCD_RS_PIN,STD_HIGH);
	DIO_vidSetPinValue(GLCD_RW_PORT,GLCD_RW_PIN,STD_LOW);
	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PIN,STD_HIGH);
	
	/*Filling in the character to be written*/
	DIO_vidSetPinValue(GLCD_D0_PORT,GLCD_D0_PIN,GET_BIT(u8CharacterCpy,0));
	DIO_vidSetPinValue(GLCD_D1_PORT,GLCD_D1_PIN,GET_BIT(u8CharacterCpy,1));
	DIO_vidSetPinValue(GLCD_D2_PORT,GLCD_D2_PIN,GET_BIT(u8CharacterCpy,2));
	DIO_vidSetPinValue(GLCD_D3_PORT,GLCD_D3_PIN,GET_BIT(u8CharacterCpy,3));
	DIO_vidSetPinValue(GLCD_D4_PORT,GLCD_D4_PIN,GET_BIT(u8CharacterCpy,4));
	DIO_vidSetPinValue(GLCD_D5_PORT,GLCD_D5_PIN,GET_BIT(u8CharacterCpy,5));
	DIO_vidSetPinValue(GLCD_D6_PORT,GLCD_D6_PIN,GET_BIT(u8CharacterCpy,6));
	DIO_vidSetPinValue(GLCD_D7_PORT,GLCD_D7_PIN,GET_BIT(u8CharacterCpy,7));
	
	_delay_us(5);
	DIO_vidSetPinValue(GLCD_EN_PORT,GLCD_EN_PIN,STD_LOW);
	_delay_us(5);
}

void GLCD_vidClearAll(void) {
		u8 i, j;
	/*Selecting both halves of the display*/
	DIO_vidSetPinValue(GLCD_CS1_PORT,GLCD_CS1_PIN,STD_HIGH);
	DIO_vidSetPinValue(GLCD_CS2_PORT,GLCD_CS1_PIN,STD_HIGH);
	
	for (i = 0; i < GLCD_TOTALPAGES; i++) {
		GLCD_vidSendCommand((0xB8)+i);
		for (j = 0; j < 64; j++) {
			GLCD_vidWriteCharacter(0);
		}
	}
		GLCD_vidSendCommand(0x40); /*Setting x address to 0*/
		GLCD_vidSendCommand(0xB8);  /*Setting y address to 0*/
}	
	
void GLCD_vidWriteString(u8 page_no, u8 *str)			/* GLCD string write function */
{
	unsigned int i, column;
	unsigned int  Page = ((0xB8) + page_no);
	unsigned int Y_address = 0;
	float Page_inc = 0.5;
	
	DIO_vidSetPinValue(GLCD_CS1_PORT,GLCD_CS1_PIN,STD_HIGH);
	DIO_vidSetPinValue(GLCD_CS2_PORT,GLCD_CS2_PIN,STD_LOW);
	
	GLCD_vidSendCommand(Page);
	for(i = 0; str[i] != 0; i++)					/* Print each char in string till null */
	{
		if (Y_address > (1024-(((page_no)*128)+FontWidth))) /* Check Whether Total Display get overflowed */
		break;										/* If yes then break writing */
		if (str[i]!=32)								/* Check whether character is not a SPACE */
		{
			for (column=1; column<=FontWidth; column++)
			{
				if ((Y_address+column)==(128*((int)(Page_inc+0.5))))	/* If yes then check whether it overflow from right side of display */
				{
					if (column == FontWidth)		/* Also check and break if it overflow after 5th column */
					break;
					GLCD_vidSendCommand(0x40);				/* If not 5th and get overflowed then change Y address to START column */
					Y_address = Y_address + column;	/* Increment Y address count by column no. */
					TOGGLE_BIT(PORTB,GLCD_CS1_PIN); /* If yes then change segment controller to display on other half of display */
					TOGGLE_BIT(PORTB,GLCD_CS2_PIN);
					GLCD_vidSendCommand(Page + Page_inc);	/* Execute command for page change */
					Page_inc = Page_inc + 0.5;		/* Increment Page No. by half */
				}
			}
		}
		if (Y_address>(1024-(((page_no)*128)+FontWidth)))   /* Check Whether Total Display get overflowed */
		break;										/* If yes then break writing */
		if((font[((str[i]-32)*FontWidth)+4])==0 || str[i]==32)/* Check whether character is SPACE or character last column is zero */
		{
			for(column=0; column<FontWidth; column++)
			{
				GLCD_vidWriteCharacter(font[str[i]-32][column]);	/* If yes then then print character */
				if((Y_address+1)%64==0)				/* check whether it gets overflowed  from either half of side */
				{
					TOGGLE_BIT(PORTB,GLCD_CS1_PIN); /* If yes then change segment controller to display on other half of display */
					TOGGLE_BIT(PORTB,GLCD_CS2_PIN);
					GLCD_vidSendCommand((Page+Page_inc));	/* Execute command for page change */
					Page_inc = Page_inc + 0.5;		/* Increment Page No. by half */
				}
				Y_address++;						/* Increment Y_address count per column */
			}
		}
		else										/* If character is not SPACE or character last column is not zero */
		{
			for(column=0; column<FontWidth; column++)
			{
				GLCD_vidWriteCharacter(font[str[i]-32][column]); /* Then continue to print hat char */
				if((Y_address+1)%64==0)				/* check whether it gets overflowed  from either half of side */
				{
					TOGGLE_BIT(PORTB,GLCD_CS1_PIN); /* If yes then change segment controller to display on other half of display */
					TOGGLE_BIT(PORTB,GLCD_CS2_PIN);
					GLCD_vidSendCommand((Page+Page_inc));	/* Execute command for page change */
					Page_inc = Page_inc + 0.5;		/* Increment Page No. by half */
				}
				Y_address++;						/* Increment Y_address count per column */
			}
			GLCD_vidWriteCharacter(0);							/* Add one column of zero to print next character next of zero */
			Y_address++;							/* Increment Y_address count for last added zero */
			if((Y_address)%64 == 0)					/* check whether it gets overflowed  from either half of side */
			{
				TOGGLE_BIT(PORTB,GLCD_CS1_PIN); /* If yes then change segment controller to display on other half of display */
				TOGGLE_BIT(PORTB,GLCD_CS2_PIN);
				GLCD_vidSendCommand((Page+Page_inc));		/* Execute command for page change */
				Page_inc = Page_inc + 0.5;			/* Increment Page No. by half */
			}
		}
	}
	GLCD_vidSendCommand(0x40);								/* Set Y address (column=0) */
}		
