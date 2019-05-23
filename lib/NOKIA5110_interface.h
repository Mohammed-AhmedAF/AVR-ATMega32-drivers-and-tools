
/*
 * NOKIA5110_interface.h
 *
 * Created: 5/23/2019 10:39:45 AM
 *  Author: Admin
 */ 


#ifndef _NOKIA5110_INTERFACE_H_
#define _NOKIA5110_INTERFACE_H_

/*Pin definitions*/
#define NOKIA5110_DC_PORT DIO_PORTB
#define NOKIA5110_RST_PORT DIO_PORTB
#define NOKIA5110_DC_PIN DIO_PIN1
#define NOKIA5110_RST_PIN DIO_PIN0


/*Command definitions*/
#define NOKIA5110_CMD_ADD_MODE 0x21
#define NOKIA5110_CMD_VOLT_5V 0xC0
#define NOKIA5110_CMD_TEMPCOEF_3 0x07
#define NOKIA5110_CMD_VOLTBIAS 0x13
#define NOKIA5110_CMD_BASIC_MODE 0x20
#define NOKIA5110_CMD_NORMAL_MODE 0x0C

void NOKIA5110_vidInit(void);
void NOKIA5110_vidReset(void);
void NOKIA5110_vidSendCommand(u8 u8CommandCpy);
void NOKIA5110_vidSendData(u8 * u8DataCpy);
void NOKIA5110_vidGoToXY(u8,u8);
void NOKIA5110_vidClearScreen(void);
void NOKIA5110_vidDrawImage(const u8 * u8ImageData);



#endif /* NOKIA5110_INTERFACE_H_ */