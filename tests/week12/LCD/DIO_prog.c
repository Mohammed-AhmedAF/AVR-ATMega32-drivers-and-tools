#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"

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
	}
}

u8 DIO_u8GetPortValue(u8 u8PortNumberCpy) {
	u8 u8Value;
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
		u8Value = PORTD;
		break;
	}
	return u8Value;
}

void DIO_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy,u8 u8ValueCpy) {
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			if (u8ValueCpy == 1) {
				Set_Bit(PORTA,u8PinNumberCpy);
			}
			else {
				Clear_Bit(PORTA,u8PinNumberCpy);
			}
			break;
		case DIO_PORTB:
			if (u8ValueCpy == 1) {
				Set_Bit(PORTB,u8PinNumberCpy);
			}
			else {
				Clear_Bit(PORTB,u8PinNumberCpy);
			}	
			break;
		case DIO_PORTC:
			if (u8ValueCpy == 1) {
				Set_Bit(PORTC,u8PinNumberCpy);
			}
			else {
				Clear_Bit(PORTC,u8PinNumberCpy);
			}						
			break;
		case DIO_PORTD:
		if (u8ValueCpy == 1) {
				Set_Bit(PORTD,u8PinNumberCpy);
			}
			else {
				Clear_Bit(PORTD,u8PinNumberCpy);
			}							
			break;
		}
}

void DIO_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy) {
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			if(u8DirectionCpy == STD_HIGH) {
				Set_Bit(DDRA,u8PinNumberCpy);
			}
			else {
				Clear_Bit(DDRA,u8PinNumberCpy);
			}
			break;
		case DIO_PORTB:
			if(u8DirectionCpy == STD_HIGH) {
				Set_Bit(DDRB,u8PinNumberCpy);
			}
			else {
				Clear_Bit(DDRB,u8PinNumberCpy);
			}
			break;
		case DIO_PORTC:
			if(u8DirectionCpy == STD_HIGH) {
				Set_Bit(DDRC,u8PinNumberCpy);
			}
			else {
				Clear_Bit(DDRC,u8PinNumberCpy);
			}
			break;
		case DIO_PORTD:
			if(u8DirectionCpy == STD_HIGH) {
				Set_Bit(DDRD,u8PinNumberCpy);
			}
			else {
				Clear_Bit(DDRD,u8PinNumberCpy);
			}
	}
}

u8 DIO_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy) {
	u8 u8Value;
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
