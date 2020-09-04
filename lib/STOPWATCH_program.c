#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "STOPWATCH_interface.h"

/*Stopwatch variables*/
volatile u8 u8SSeconds = 0;
volatile u8 u8SMinutes = 0;
volatile u8 u8StopwatchFlag = 0;


void STOPWATCH_vidToggle()
{
	u8StopwatchFlag ^= (1<<0);
	LCD_vidGoToXY(LCD_XPOS0,LCD_YPOS3);
	LCD_vidWriteString("Stop wa.:");
}

void STOPWATCH_vidRun(void)
{
	u8SSeconds++;
	if (u8SSeconds == 60)
	{
		u8SSeconds = 0;
		u8SMinutes++;
	}

	/*Minutes*/
	LCD_vidGoToXY(LCD_XPOS9,LCD_YPOS3);
	LCD_vidWriteNumber(u8SMinutes);
	LCD_vidWriteCharacter(':');
	/*Seconds*/
	LCD_vidGoToXY(LCD_XPOS12,LCD_YPOS3);
	LCD_vidWriteNumber(u8SSeconds);

}

void STOPWATCH_vidStop(void)
{
	u8SSeconds = 0;
	u8SMinutes = 0;
}

u8 STOPWATCH_u8CheckFlag(void)
{
	return u8StopwatchFlag;
}
