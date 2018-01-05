/*
 * dio.h
 *
 *  Created on: 4 Jan 2018
 *      Author: mohamed
 */

#ifndef DIO_H_
#define DIO_H_

typedef char u8;

#define DDRA *((u8*) 0x3A)
#define PORTA *((u8*) 0x3B)
#define PINA *((u8*) 0x39)
#define DDRB *((u8*) 0x37)
#define PORTB *((u8*) 0x38)
#define PORTC *((u8*)0x35)
#define DDRC *((u8*)0x34)
#define DDRD *((u8*)0x31)
#define PORTD *((u8*)0x32)

#endif /* DIO_H_ */
