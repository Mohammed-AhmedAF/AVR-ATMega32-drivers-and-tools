#ifndef DIO_H
#define DIO_H


#define F_CPU (8000000UL)

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DDRA *((u8*) 0x3A)
#define PORTA *((u8*) 0x3B)
#define PINA *((u8*) 0x39)

#define DDRB *((u8*) 0x37)
#define PORTB *((u8*) 0x38)
#define PINB *((u8*) 0x36)

#define DDRC *((u8*) 0x34) 
#define PORTC *((u8*) 0x35)
#define PINC *((u8*) 0x33)

#define DDRD *((u8*) 0x31)
#define PORTD *((u8*) 0x32)
#define PIND *((u8*) 0x30)

void DIO_vidSetPortDirection(u8 u8PortNumberCpy, u8 u8DirectionCpy);
void DIO_vidSetPortValue(u8 u8PortNumberCpy, u8 u8ValueCpy);
u8 DIO_u8GetPortValue(u8 u8PortNumberCpy);

void DIO_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy);
void DIO_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy);
u8 DIO_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy);

#endif
