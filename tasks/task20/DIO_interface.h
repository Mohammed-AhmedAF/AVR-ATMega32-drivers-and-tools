/*
 * Dio.h
 *
 *  Created on: Jan 6, 2018
 *      Author: adel
 */
#include "./Std_Types.h"
#ifndef DIO_H_
#define DIO_H_

#define F_CPU 8000000

#define DIO_PORTA 0

#define DIO_PORTB 1

#define DIO_PORTC 2

#define DIO_PORTD 3



#define DDRA (*((u8*)0x3A))

#define DDRB (*((u8*)0x37))

#define DDRC (*((u8*)0x34))

#define DDRD (*((u8*)0x31))



#define PORTA (*((u8*)0x3B))

#define PORTB (*((u8*)0x38))

#define PORTC (*((u8*)0x35))

#define PORTD (*((u8*)0x32))



#define PINA (*((u8*)0x39))

#define PINB (*((u8*)0x36))

#define PINC (*((u8*)0x33))

#define PIND (*((u8*)0x30))

#define PIN_NUMBER0 0
#define PIN_NUMBER1 1
#define PIN_NUMBER2 2
#define PIN_NUMBER3 3
#define PIN_NUMBER4 4
#define PIN_NUMBER5 5
#define PIN_NUMBER6 6
#define PIN_NUMBER7 7

void DIO_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy);
u8 DIO_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy);
void DIO_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy);
void DIO_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8ValueCpy);
void DIO_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy);
u8 DIO_u8GetPortValue(u8 u8PortNumberCpy) ;

#endif /* DIO_H_ */
