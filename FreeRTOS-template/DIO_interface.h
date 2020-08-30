/* 
 * Author: Mohamed Ahmed Abd Al-Fattah Mahmoud
 */

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H


#define F_CPU (8000000UL)

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define DIO_PORTE 4
#define DIO_PORTF 5
#define DIO_PORTG 6

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_OUTPUT 1
#define DIO_INPUT 0

void DIO_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8DirectionCpy);
void DIO_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy);
u8 DIO_u8GetPortValue(u8 u8PortNumberCpy);

void DIO_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy);
void DIO_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy);
u8 DIO_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy);

void DIO_vidTogglePin(u8,u8);

void DIO_vidSetPullUpOnPin(u8 u8PortNumber,u8 u8PinNumber);

#endif
