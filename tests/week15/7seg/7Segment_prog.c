#include "DIO_interface.h"
#include "Std_Types.h"
#include "Macros.h"
#include "7Segment_interface.h"

u8 num[10] = {0b10100000,0b10101111,0b11000100,0b10000110,0b10001011,0b10010010,0b10010000,0b10100111,0b10000000,
	0b10000010};
u8 u8port0 = 0;
u8 u8port1 = 0;
u8 u8val0 = 0;
u8 u8val1 = 0;
void SevenSegment_vidInit(u8 u8port1Cpy,u8 u8port2Cpy, u8 u8display1Anode, u8 u8display2Anode) {
	u8port0 = u8port2Cpy;
	u8port1 = u8port1Cpy;
	/*Display 0*/	
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN0,1);
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN1,1);
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN2,1);
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN3,1);
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN4,1);
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN5,1);
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN6,1);
	DIO_vidSetPinDirection(u8port1Cpy,DIO_PIN7,1);

	/*Display 1*/
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN0,1);
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN1,1);
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN2,1);
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN3,1);
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN4,1);
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN5,1);
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN6,1);
	DIO_vidSetPinDirection(u8port2Cpy,DIO_PIN7,1);

	/*Setting common anode*/
	DIO_vidSetPinDirection(DIO_PORTA,u8display1Anode,1);
	DIO_vidSetPinDirection(DIO_PORTC,u8display2Anode,1);
	SET_BIT(PORTA,u8display1Anode);
	SET_BIT(PORTC,u8display2Anode);

}

/*vidWriteNumber() will take an integer number from 0 : 255,
 * but of course it will display numbers till 99;
 */
void SevenSegment_vidWriteNumber(u8 u8numCpy) {
	if (u8numCpy < 10) {
		u8val0 = num[u8numCpy];
		DIO_vidSetPortValue(u8port0,u8val0);
		u8val1 = num[0];
		DIO_vidSetPortValue(u8port1,u8val1);
	}
	else {
		u8val0 = num[(u8numCpy%10)];
		DIO_vidSetPortValue(u8port0,u8val0);
		u8val1 = num[u8numCpy/10];
		DIO_vidSetPortValue(u8port1,u8val1);

	}
}
