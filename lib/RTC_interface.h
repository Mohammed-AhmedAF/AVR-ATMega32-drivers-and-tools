#ifndef _RTC_INTERFACE_H
#define _RTC_INTERFACE_H

typedef struct {
	u8 u8Seconds;
	u8 u8Minutes;
	u8 u8Hours;
} RTC_t;
#define C_Ds1307ReadMode_U8   0xD1u  // DS1307 ID
#define C_Ds1307WriteMode_U8  0xD0u  // DS1307 ID

void RTC_vidInit(void);
void RTC_vidSetTime(RTC_t *);
void RTC_vidGetTime(RTC_t *);

u8 RTC_DEC2BCD(u8);
u8 RTC_BCD2DEC(u8);



#endif
