#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

/*Register definitions*/
#define DDRA *((u8*) 0x3A)
#define PORTA *((volatile u8*) 0x3B)
#define PINA *((u8*) 0x39)

#define DDRB *((u8*) 0x37)
#define PORTB *((volatile u8*) 0x38)
#define PINB *((u8*) 0x36)

#define DDRC *((u8*) 0x34) 
#define PORTC *((volatile u8*) 0x35)
#define PINC *((u8*) 0x33)

#define DDRD *((u8*) 0x31)
#define PORTD *((volatile u8*) 0x32)
#define PIND *((u8*) 0x30)

#define DDRE *((u8*) 0x22)
#define PORTE *((volatile u8*) 0x23)
#define PINE *((u8*) 0x21)

#define DDRF *((u8*) 0x61)
#define PORTF *((volatile u8*) 0x62)
#define PINF *((u8*) 0x20)

#define DDRG *((u8*) 0x64)
#define PORTG *((volatile u8*) 0x65)
#define PING *((u8*) 0x63)

#endif
