#ifndef _ADC_INTERFACE_H

void ADC_vidInit(u8,u8,u8,u8);
void ADC_vidStartConversion(void);
void ADC_vidSetAutoTrigger(void);
u8 ADC_u8GetValue(void);
u8 ADC_u8GetADCH(void);
u8 ADC_u8GetADCL(void);

#define ADC_MUX_0 0
#define ADC_MUX_1 1
#define ADC_MUX_2 2
#define ADC_MUX_3 3
#define ADC_MUX_4 4
#define ADC_MUX_5 5
#define ADC_MUX_6 6
#define ADC_MUX_7 7

#define ADC_REF_AREF 0
#define ADC_REF_AVCC 1
#define ADC_REF_RESERVED 2
#define ADC_REF_INTERNAL 3

#define ADC_LEFTADJUST 0
#define ADC_RIGHTADJUST 1

#define ADC_CLK_2 1
#define ADC_CLK_4 2
#define ADC_CLK_8 3
#define ADC_CLK_16 4
#define ADC_CLK_32 5
#define ADC_CLK_64 6
#define ADC_CLK_128 7

#endif
