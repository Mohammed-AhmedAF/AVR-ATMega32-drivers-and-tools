#include "Std_Types.h"
#include "Macros.h"
#include "TWI_interface.h"
#include "RTC_interface.h"

u8 RTC_DEC2BCD(u8 val)
{
	return (val + 6*(val/10));
}

u8 RTC_BCD2DEC(u8 val)
{
	return (val - 6*(val>>4));
}

void RTC_vidInit(void)
{
	TWI_vidInit();
	TWI_vidSendStart();

	TWI_vidSendByte(0xd0);
	/*Sending address of control register*/
	TWI_vidSendByte(0x07);
	TWI_vidSendByte(0x00);

	TWI_vidSendStop();


}

/*Write time to RTC: Complete*/
void RTC_vidSetTime(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x00);
	TWI_vidSendByte(rtc->u8Seconds);
	TWI_vidSendByte(rtc->u8Minutes);
	TWI_vidSendByte(rtc->u8Hours);
	TWI_vidSendByte(0x00);
	TWI_vidSendStop();
}

void RTC_vidGetTime(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x00);
	TWI_vidSendStop();

	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_READ);

	rtc->u8Seconds = TWI_u8ReceiveWithAck();
	TWI_u8CheckAck(0x01);
	rtc->u8Minutes = TWI_u8ReceiveWithAck();
	TWI_u8CheckAck(0x01);
	rtc->u8Hours = TWI_u8ReceiveWithNoAck();

	TWI_vidSendStop();
}

void RTC_vidSetDate(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x04);
	TWI_vidSendByte(rtc->u8Days);
	TWI_vidSendByte(rtc->u8Months);
	TWI_vidSendByte(rtc->u8Years);
	TWI_vidSendByte(0x00);
	TWI_vidSendStop();
}

void RTC_vidGetDate(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x04);
	TWI_vidSendStop();

	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_READ);

	rtc->u8Days = TWI_u8ReceiveWithAck();
	TWI_u8CheckAck(0x01);
	rtc->u8Months = TWI_u8ReceiveWithAck();
	TWI_u8CheckAck(0x01);
	rtc->u8Years = TWI_u8ReceiveWithNoAck();

	TWI_vidSendStop();

}

void RTC_vidSetDayOfWeek(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x03);

	TWI_vidSendByte(rtc->u8DayOfWeek);
	TWI_vidSendStop();
}

void RTC_vidGetDayOfWeek(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x03);
	TWI_vidSendStop();

	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_READ);
	rtc->u8DayOfWeek = TWI_u8ReceiveWithNoAck();
	TWI_vidSendStop();

}
