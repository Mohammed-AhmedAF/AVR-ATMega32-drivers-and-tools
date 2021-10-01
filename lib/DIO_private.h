#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

/*Register definitions*/
#define DDRA *((volatile u8* const) 0x3A)
#define PORTA *((volatile u8* const) 0x3B)
#define PINA *((volatile u8* const) 0x39)

#ifdef ST_MC_ATMEGA328P
#define DDRB *((volatile u8* const) 0x24)
#define PORTB *((volatile u8* const) 0x25)
#define PINB *((volatile u8* const) 0x23)
#else
#define DDRB *((volatile u8* const) 0x24)
#define PORTB *((volatile u8* const) 0x25)
#define PINB *((volatile u8* const) 0x23)
#endif

#define DDRC *((volatile u8* const) 0x34) 
#define PORTC *((volatile u8* const) 0x35)
#define PINC *((volatile u8* const) 0x33)

#ifdef ST_MC_ATMEGA328P
#define DDRD *((volatile u8* const) 0x2A)
#define PORTD *((volatile u8* const) 0x2B)
#define PIND *((volatile u8* const) 0x29)
#else
#define DDRD *((volatile u8* const) 0x31)
#define PORTD *((volatile u8* const) 0x32)
#define PIND *((volatile u8* const) 0x30)
#endif

#define DDRE *((volatile u8* const) 0x22)
#define PORTE *((volatile u8* const) 0x23)
#define PINE *((volatile u8* const) 0x21)

#define DDRF *((volatile u8* const) 0x61)
#define PORTF *((volatile u8* const) 0x62)
#define PINF *((volatile u8* const) 0x20)

#define DDRG *((volatile u8* const) 0x64)
#define PORTG *((volatile u8* const) 0x65)
#define PING *((volatile u8* const) 0x63)

#endif
