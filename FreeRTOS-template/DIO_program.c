/*
 * Author: Mohammed Ahmed Abd Al-Fattah Mahmoud
 * Purpose: DIO driver for AVR Atmega32
 */

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_private.h"
#include "DIO_interface.h"

void DIO_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy) {
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			PORTA = u8ValueCpy;
			break;
		case DIO_PORTB:
			PORTB = u8ValueCpy;
			break;
		case DIO_PORTC:
			PORTC = u8ValueCpy;
			break;
		case DIO_PORTD:
			PORTD = u8ValueCpy;
			break;
	}
}

void DIO_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8DirectionCpy) {
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			DDRA = u8DirectionCpy;
			break;
		case DIO_PORTB:
			DDRB = u8DirectionCpy;
			break;
		case DIO_PORTC:
			DDRC = u8DirectionCpy;
			break;
		case DIO_PORTD:
			DDRD = u8DirectionCpy;
			break;
		case DIO_PORTE:
			DDRE = u8DirectionCpy;
			break;
		case DIO_PORTF:
			DDRF = u8DirectionCpy;
			break;
		case DIO_PORTG:
			DDRG = u8DirectionCpy;
			break;
	}
}

u8 DIO_u8GetPortValue(u8 u8PortNumberCpy) {
	u8 u8Value  = 0x00;
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			u8Value = PINA;
			break; 
		case DIO_PORTB:
			u8Value = PINB;
			break;
		case DIO_PORTC:
			u8Value = PINC;
			break;
		case DIO_PORTD:
			u8Value = PIND;
			break;
		case DIO_PORTE:
			u8Value = PINE;
			break;
		case DIO_PORTF:
			u8Value = PINF;
			break;
		case DIO_PORTG:
			u8Value = PING;
			break;
	}
	return u8Value;
}

void DIO_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy,u8 u8ValueCpy) {
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			if (u8ValueCpy == STD_HIGH) {
				SET_BIT(PORTA,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(PORTA,u8PinNumberCpy);
			}
			break;
		case DIO_PORTB:
			if (u8ValueCpy == STD_HIGH) {
				SET_BIT(PORTB,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(PORTB,u8PinNumberCpy);
			}	
			break;
		case DIO_PORTC:
			if (u8ValueCpy == STD_HIGH) {
				SET_BIT(PORTC,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(PORTC,u8PinNumberCpy);
			}						
			break;
		case DIO_PORTD:
			if (u8ValueCpy == STD_HIGH) {
				SET_BIT(PORTD,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(PORTD,u8PinNumberCpy);
			}							
			break;
		case DIO_PORTE:
			if (u8ValueCpy == STD_HIGH)
			{
			SET_BIT(PORTE,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(PORTE,u8PinNumberCpy);
			}
	}
}

void DIO_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy) {
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			if(u8DirectionCpy == DIO_OUTPUT) {
				SET_BIT(DDRA,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(DDRA,u8PinNumberCpy);
			}
			break;
		case DIO_PORTB:
			if(u8DirectionCpy == DIO_OUTPUT) {
				SET_BIT(DDRB,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(DDRB,u8PinNumberCpy);
			}
			break;
		case DIO_PORTC:
			if(u8DirectionCpy == DIO_OUTPUT) {
				SET_BIT(DDRC,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(DDRC,u8PinNumberCpy);
			}
			break;
		case DIO_PORTD:
			if(u8DirectionCpy == DIO_OUTPUT) {
				SET_BIT(DDRD,u8PinNumberCpy);
			}
			else {
				CLEAR_BIT(DDRD,u8PinNumberCpy);
			}
	}
}

u8 DIO_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy) {
	u8 u8Value = 0;
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			u8Value = GET_BIT(PINA,u8PinNumberCpy);
			break;
		case DIO_PORTB:
			u8Value = GET_BIT(PINB,u8PinNumberCpy);
			break;
		case DIO_PORTC:
			u8Value = GET_BIT(PINC, u8PinNumberCpy);
			break;
		case DIO_PORTD:
			u8Value = GET_BIT(PIND,u8PinNumberCpy);
			break;
	}
	return u8Value;
}

void DIO_vidTogglePin(u8 u8PortNumberCpy, u8 u8PinNumberCpy) {
	switch (u8PortNumberCpy) {
		case DIO_PORTA:
			TOGGLE_BIT(PORTA,u8PinNumberCpy);
			break;
		case DIO_PORTB:
			TOGGLE_BIT(PORTB,u8PinNumberCpy);
			break;
		case DIO_PORTC:
			TOGGLE_BIT(PORTC,u8PinNumberCpy);
			break;
		case DIO_PORTD:
			TOGGLE_BIT(PORTD,u8PinNumberCpy);
			break;
	}
}

void DIO_vidSetPullUpOnPin(u8 u8PortNumber, u8 u8PinNumber) {
	DIO_vidSetPinDirection(u8PinNumber,u8PinNumber,DIO_INPUT);
	DIO_vidSetPinValue(u8PortNumber,u8PinNumber,STD_HIGH);
}
