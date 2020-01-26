#ifndef _RTC_INTERFACE_H
#define _RTC_INTERFACE_H

typedef struct {
	u8 u8Seconds;
	u8 u8Minutes;
	u8 u8Hours;
	u8 u8DayOfWeek;
	u8 u8Days;
	u8 u8Months;
	u16 u8Years;
} RTC_t;
#define C_Ds1307ReadMode_U8   0xD1u  // DS1307 ID
#define C_Ds1307WriteMode_U8  0xD0u  // DS1307 ID

#define RTC_MODE_WRITE 0xD0
#define RTC_MODE_READ 0xD1


void RTC_vidInit(void);
void RTC_vidSetTime(RTC_t *);
void RTC_vidGetTime(RTC_t *);
void RTC_vidSetDate(RTC_t *);
void RTC_vidGetDate(RTC_t *);
void RTC_vidSetDayOfWeek(RTC_t *);
void RTC_vidGetDayOfWeek(RTC_t *);

u8 RTC_DEC2BCD(u8);
u8 RTC_BCD2DEC(u8);



#endif
