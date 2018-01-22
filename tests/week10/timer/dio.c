#include "dio.h"
#include "Std_Types.h"
#include "Macros.h"

void Dio_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy) {
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

void Dio_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8DirectionCpy) {
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

u8 Dio_u8GetPortValue(u8 u8PortNumberCpy) {
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

void Dio_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy,u8 u8ValueCpy) {
	u8 u8Port;
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
void Dio_u8SetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy) {
	u8 u8Port;
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
			u8Port = DDRA;
			break;
		case DIO_PORTB:
			u8Port = DDRB;
			break;
		case DIO_PORTC:
			u8Port = DDRC;
			break;
		case DIO_PORTD:
			u8Port = DDRD;
			break;
	}
	if (u8DirectionCpy == STD_HIGH) {
		Set_Bit (u8Port,u8PinNumberCpy);	
	}
	else {
		Clear_Bit (u8Port,u8PinNumberCpy);
	}
}

u8 Dio_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy) {
	u8 u8Value;
	switch(u8PortNumberCpy) {
		case DIO_PORTA:
		u8Value = Get_Bit(PINA,u8PinNumberCpy);
		break;
		case DIO_PORTB:
		u8Value = Get_Bit(PINB,u8PinNumberCpy);
		break;
		case DIO_PORTC:
		u8Value = Get_Bit(PINC, u8PinNumberCpy);
		break;
		case DIO_PORTD:
		u8Value = Get_Bit(PIND,u8PinNumberCpy);
		break;
	}
	return u8Value;
}
