#ifndef _TIMER1_PRIVATE_H
#define _TIMER1_PRIVATE_H

/*Register definitions*/
#define TCCR1A *((u32*) 0x4F)
#define TCCR1B *((u32*) 0x4E)
#define OCR1AH *((u32*) 0x4A)
#define OCR1AL *((u32*) 0x4B)
#define OCR1A * ((u32*) 0x4B)
#define OCR1BH *((u32*) 0x49)
#define OCR1BL  *((u32*) 0x48)
#define OCR1B * ((u32*) 0x48)


#endif
