/*
 * Dio.c
 *
 *  Created on: Jan 6, 2018
 *      Author: adel
 */
#include "./DIO_interface.h"
#include "./Macros.h"
#include "./Std_Types.h"

void DIO_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy){
	switch(u8PortNumberCpy){
	case 0:
		if(u8ValueCpy == STD_HIGH)
			SET_BIT(PORTA,u8PinNumberCpy);
		else if(u8ValueCpy == STD_LOW)
			CLEAR_BIT(PORTA,u8PinNumberCpy);
		break;
	case 1:
		if(u8ValueCpy == STD_HIGH)
			SET_BIT(PORTB,u8PinNumberCpy);
		else if(u8ValueCpy == STD_LOW)
			CLEAR_BIT(PORTB,u8PinNumberCpy);
		break;
	case 2:
		if(u8ValueCpy == STD_HIGH)
			SET_BIT(PORTC,u8PinNumberCpy);
		else if(u8ValueCpy == STD_LOW)
			CLEAR_BIT(PORTC,u8PinNumberCpy);
		break;

	case 3:
		if(u8ValueCpy == STD_HIGH)
			SET_BIT(PORTD,u8PinNumberCpy);
		else if(u8ValueCpy == STD_LOW)
			CLEAR_BIT(PORTD,u8PinNumberCpy);
		break;
	}
}

u8 DIO_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy){
	u8 u8PinValue;
	switch(u8PortNumberCpy){
	case 0:
		u8PinValue=GET_BIT(PINA,u8PinNumberCpy);
		break;
	case 1:
		u8PinValue=GET_BIT(PINB,u8PinNumberCpy);

		break;
	case 2:
		u8PinValue=GET_BIT(PINC,u8PinNumberCpy);

		break;
	case 3:
		u8PinValue=GET_BIT(PIND,u8PinNumberCpy);
		break;


	}
	return u8PinValue;
}
void DIO_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy){
	switch(u8PortNumberCpy){
	case 0:
		if(u8DirectionCpy == STD_HIGH)
			SET_BIT(DDRA,u8PinNumberCpy);
		else if (u8DirectionCpy == STD_LOW)
			CLEAR_BIT(DDRA,u8PinNumberCpy);
		break;
	case 1:
		if(u8DirectionCpy == STD_HIGH)
			SET_BIT(DDRB,u8PinNumberCpy);
		else if(u8DirectionCpy == STD_LOW)
			CLEAR_BIT(DDRB,u8PinNumberCpy);
		break;
	case 2:
		if(u8DirectionCpy == STD_HIGH)
			SET_BIT(DDRC,u8PinNumberCpy);
		else if(u8DirectionCpy == STD_LOW)
			CLEAR_BIT(DDRC,u8PinNumberCpy);
		break;
	case 3:
		if(u8DirectionCpy == STD_HIGH)
			SET_BIT(DDRD,u8PinNumberCpy);
		else if(u8DirectionCpy == STD_LOW)
			CLEAR_BIT(DDRD,u8PinNumberCpy);
		break;


	}
}
void DIO_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8ValueCpy){
	switch(u8PortNumberCpy){
	case 0:
		DDRA= u8ValueCpy;
		break;
	case 1:
		DDRB= u8ValueCpy;
		break;
	case 2:
		DDRC= u8ValueCpy;
		break;
	case 3:
		DDRD= u8ValueCpy;
		break;


	}
}
void DIO_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy){
	switch(u8PortNumberCpy){
	case 0:
		PORTA= u8ValueCpy;
		break;
	case 1:
		PORTB= u8ValueCpy;
		break;
	case 2:
		PORTC= u8ValueCpy;
		break;
	case 3:
		PORTD= u8ValueCpy;
		break;


	}
}
u8 DIO_u8GetPortValue(u8 u8PortNumberCpy){
	switch(u8PortNumberCpy){
	case 0:
		return PINA;
		break;
	case 1:
		return PINB;
		break;
	case 2:
		return PINC;
		break;
	case 3:
		return PIND;
		break;


	}
}
