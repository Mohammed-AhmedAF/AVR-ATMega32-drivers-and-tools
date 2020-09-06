/*****************************************************************
 * Purpose: STOPWATCH APP layer driver, works with character LCD
 *****************************************************************/

#include "Std_Types.h"
#include "Macros.h"
#include "LCD_interface.h"
#include "STOPWATCH_config.h"
#include "STOPWATCH_interface.h"

/*Stopwatch variables*/
volatile u8 u8dSeconds = 0;
volatile u8 u8SSeconds = 0;
volatile u8 u8SMinutes = 0;
volatile u8 u8StopwatchFlag = 0;


void STOPWATCH_vidToggle()
{
	u8StopwatchFlag ^= (1<<0);
	LCD_vidGoToXY(STOPWATCH_XPOS,STOPWATCH_YPOS);
}

void STOPWATCH_vidRun(void)
{
	u8dSeconds++;

	if (u8dSeconds == 10)
	{
		u8dSeconds = 0;
		u8SSeconds++;
	}
	if (u8SSeconds == 60)
	{
		u8SSeconds = 0;
		u8SMinutes++;
	}

	/*Minutes*/
	LCD_vidGoToXY(STOPWATCH_XPOS,STOPWATCH_YPOS);
	LCD_vidWriteNumber(u8SMinutes);
	LCD_vidWriteCharacter(':');
	/*Seconds*/
	LCD_vidWriteNumber(u8SSeconds);
	LCD_vidWriteCharacter(':');
	/*Milli-seconds*/
	LCD_vidWriteNumber(u8dSeconds);

}

/*To be used as a task*/
void STOPWATCH_vidUpdate(void)
{
	u8dSeconds++;

	if (u8dSeconds == 10)
	{
		u8dSeconds = 0;
		u8SSeconds++;
	}
	if (u8SSeconds == 60)
	{
		u8SSeconds = 0;
		u8SMinutes++;
	}

	/*Minutes*/
	LCD_vidGoToXY(LCD_XPOS0,LCD_YPOS3);
	LCD_vidWriteNumber(u8SMinutes);
	LCD_vidWriteCharacter(':');
	/*Seconds*/
	LCD_vidWriteNumber(u8SSeconds);
	LCD_vidWriteCharacter(':');
	/*Milli-seconds*/
	LCD_vidWriteNumber(u8dSeconds);

}

void STOPWATCH_vidStop(void)
{
	u8dSeconds = 0;
	u8SSeconds = 0;
	u8SMinutes = 0;
}

/*Check if stopwatch is running or not*/
u8 STOPWATCH_u8CheckFlag(void)
{
	return u8StopwatchFlag;
}
