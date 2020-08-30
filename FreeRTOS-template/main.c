/*
* First RTOS.c
*
* Created: 4/13/2020 9:28:13 PM
* Author : Mohammed
*/
#include <stdio.h>
#include "Macros.h"
#include "Std_Types.h"
#include "FreeRTOS.h"
#include "task.h"
#include "DIO_interface.h"

void vidBlinkOne(void *);
void vidBlinkTwo(void *);

TaskHandle_t BlinkOne_Handle = NULL;

int main(void)
{
	/* Replace with your application code */
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	
	
	xTaskCreate(vidBlinkOne,"one",200,NULL, 1,&BlinkOne_Handle);
	xTaskCreate(vidBlinkTwo,"two",200,NULL, 2,NULL);
	
	
	vTaskStartScheduler();


}

void vidBlinkOne(void * pt)
{
	u8 u8Count = 0;
	
	while (1)
	{
		u8Count++;
		DIO_vidTogglePin(DIO_PORTA,DIO_PIN0);
		
				vTaskDelay(1000);

	}
}

void vidBlinkTwo(void * pt)
{
	DIO_vidTogglePin(DIO_PORTA,DIO_PIN1);
	vTaskDelay(1000);
}
