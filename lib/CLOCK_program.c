/*
 * Author: Mohamed Ahmed Abd Al-Fattah
 * Purpose: CLOCK application module
 *
 */

#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "CLOCK_interface.h"

/*Global variables modified in ISR*/
volatile u8 u8AlarmFlag = CLOCK_ALARM_CLEARED;
volatile u32 u32OvFCount;
volatile u8 u8Sec = 0;
volatile u8 u8Minute = 33;
volatile u8 u8Hours = 21;
volatile u8 u8AlarmMinute = 35;


/*This function will initiate the clock*/
void CLOCK_vidInit(void) {
	/*DIO configuration for */	
	DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	DIO_vidSetPinValue(DIO_PORTD,DIO_PIN0,STD_LOW);
}

void CLOCK_vidCount(void) {
	u32OvFCount++;
	if (u32OvFCount == CLOCK_SEC_OVFCOUNT) {
		u32OvFCount = 0;
		u8Sec++;
		if (u8Sec == 60) {
			u8Sec = 0;
			u8Minute++;
			if (u8AlarmFlag == CLOCK_ALARM_SET) {
			}
			if (u8Minute == 60) {
				u8Minute = 0;
				u8Hours++;
				if (u8Hours == 23) {
					u8Hours = 0;
				}
			}
		}
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS0,u8Hours/10+'0');	
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS1,u8Hours%10+'0');
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS2,':');
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS3,u8Minute/10+'0');
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS4,u8Minute%10+'0');
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS5,':');
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS6,u8Sec/10+'0');
		LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS7,u8Sec%10+'0');
#ifdef CLOCK_AMPM_SWITCH
		if (u8Hours <= 12) {
			LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS9,'A');
			LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS10,'M');
		}
		else {
			LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS9,'p');
			LCD_vidWriteInPlace(LCD_XPOS_SHIFT+LCD_XPOS10,'M');
		}
#endif
	}

}

void CLOCK_vidIncrementHours(void) {
	u8Hours++;
}

void CLOCK_vidIncrementMinutes(void) {
	u8Minute++;
}

/*
 * This function will be called every minute to check if alarm
 *value has been reached.
 * */
void CLOCK_vidCheckAlarm(void) {
	if (u8Minute == u8AlarmMinute) {
		LCD_vidGoToXY(1,2);
		LCD_vidWriteString("Alarm");
	}
}
