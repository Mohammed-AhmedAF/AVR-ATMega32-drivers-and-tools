#ifndef _TIMER0_PRIVATE_H
#define _TIMER0_PRIVATE_H

#define TCCR0 *((volatile u8* const) 0x53)
#define TCNT0 *((volatile u8* const) 0x52)
#define OCR0 *((volatile u8* const) 0x5C)

#endif
