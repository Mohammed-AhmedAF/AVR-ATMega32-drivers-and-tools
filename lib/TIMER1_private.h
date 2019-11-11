#ifndef _TIMER1_PRIVATE_H
#define _TIMER1_PRIVATE_H

/*Register definitions*/
#define TCCR1A *((volatile u8* const) 0x4F)
#define TCCR1B *((volatile u8* const) 0x4E)
#define OCR1AH *((volatile u8* const) 0x4A)
#define OCR1AL *((volatile u8* const) 0x4B)
#define OCR1A * ((volatile u8* const) 0x4B)
#define OCR1BH *((volatile u8* const) 0x49)
#define OCR1BL  *((volatile u8* const) 0x48)
#define OCR1B *((volatile u8* const) 0x48)


#endif
