/*
 * Project: Password system with UART
 * Developer: Mohamed Ahmed
 * Date: 5 March 2018
 * Details: Using UART to connect Laptop to microcontroller
 **Keyboard will be used to enter ID and password.
 */

#include "Macros.h"
#include "Std_Types.h"
#include "DIO_interface.h"
#include "Password_interface.h"
#include "StepperMotor_interface.h"
#include "UART_interface.h"
#include <util/delay.h>

u8 k;
u8 u8count = 1;
extern u8 u8success;
void main(void) {
	/*Initialization*/
	UART_vidInit();
	StepperMotor_vidInit();

	DIO_vidSetPinDirection(DIO_PORTC,DIO_PIN0,STD_HIGH);
	DIO_vidSetPinDirection(DIO_PORTC,DIO_PIN1,STD_HIGH);

	DIO_vidSetPinValue(DIO_PORTC,DIO_PIN0,STD_HIGH);
	DIO_vidSetPinValue(DIO_PORTC,DIO_PIN1,STD_LOW);


	/*Check for password match*/
	Password_vidAskID();
	Password_vidAskPassword();
	do {
		Password_vidAskReenter();
		Password_vidCheckMatch();
	}while(u8saveFlag != 1);
	u8saveFlag = 0;
	do {
		Password_vidCheckID(1);
	}while(u8foundFlag == 0);
	for(k = 0; k<3; k++) {
		Password_vidCheckPassword(u8count);
		if (u8success == 1) {
			DIO_vidSetPinValue(DIO_PORTC,DIO_PIN0,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTC,DIO_PIN1,STD_HIGH);
			StepperMotor_vidMove();
			break;
		}
		else if (k == 2) {
			UART_vidSendLine();
			UART_vidSendString(SYSTEM_FAILED);
		}
		u8count++;
	}
}
