#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "HBRIDGE_interface.h"

void HBRIDGE_vidInit(void)
{
	/*Right side*/
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);

	/*Left side*/	
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
}

void HBRIDGE_vidControl(u8 u8Command) {
	switch(u8Command) 
	{
		case HBRIDGE_BOTH_FORWARD:
			/*Right*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,STD_HIGH);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,STD_LOW);
			/*Left*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_HIGH);
			break;
		case HBRIDGE_BOTH_BACKWARD:
			/*Right*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,STD_HIGH);
			/*Left*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_HIGH);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_LOW);
			break;
		case HBRIDGE_BOTH_STOP:
			/*Right*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,STD_LOW);
			/*Left*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_LOW);
			break;
		case HBRIDGE_RIGHT_FORWARD:
			/*Right*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,STD_HIGH);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,STD_LOW);
			/*Left*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_LOW);
			break;
		case HBRIDGE_RIGH_BACKWARD:
			/*Right*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,STD_HIGH);
			/*Left*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_LOW);
			break;
		case HBRIDGE_LEFT_FORWARD:
			/*Right*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,STD_LOW);
			/*Left*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_HIGH);
			break;
		case HBRIDGE_LEFT_BACKWARD:
			/*Right*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN0,STD_LOW);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN1,STD_LOW);
			/*Left*/
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN2,STD_HIGH);
			DIO_vidSetPinValue(DIO_PORTA,DIO_PIN3,STD_LOW);
			break;
	}
}
