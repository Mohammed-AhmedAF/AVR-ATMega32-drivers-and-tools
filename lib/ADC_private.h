#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H

#define ADMUX *((volatile u8* const) 0x27)
#define ADCSRA *((volatile u8* const) 0x26)
#define ADCH *((volatile u8* const) 0x25)
#define ADCL *((volatile u8* const) 0x24)

#endif
