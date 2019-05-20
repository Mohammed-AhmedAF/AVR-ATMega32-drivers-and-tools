/*
 * GLCD_interface.h
 *
 * Created: 5/20/2019 9:16:13 AM
 *  Author: Admin
 */ 


#ifndef _GLCD_INTERFACE_H_
#define _GLCD_INTERFACE_H_


/*Command port definitions*/
#define GLCD_EN_PORT DIO_PORTB
#define GLCD_RW_PORT DIO_PORTB
#define GLCD_RS_PORT DIO_PORTB
#define GLCD_CS1_PORT DIO_PORTB
#define GLCD_CS2_PORT DIO_PORTB
#define GLCD_RST_PORT DIO_PORTB

/*Command pin definitions*/
#define GLCD_EN_PIN DIO_PIN2
#define GLCD_RW_PIN DIO_PIN1
#define GLCD_RS_PIN DIO_PIN0
#define GLCD_CS1_PIN DIO_PIN4
#define GLCD_CS2_PIN DIO_PIN5
#define GLCD_RST_PIN DIO_PIN3

/*Data port definitions*/
#define GLCD_D0_PORT DIO_PORTA
#define GLCD_D1_PORT DIO_PORTA
#define GLCD_D2_PORT DIO_PORTA
#define GLCD_D3_PORT DIO_PORTA
#define GLCD_D4_PORT DIO_PORTA
#define GLCD_D5_PORT DIO_PORTA
#define GLCD_D6_PORT DIO_PORTA
#define GLCD_D7_PORT DIO_PORTA

/*Data pin definitions*/
#define GLCD_D0_PIN DIO_PIN0
#define GLCD_D1_PIN DIO_PIN1
#define GLCD_D2_PIN DIO_PIN2
#define GLCD_D3_PIN DIO_PIN3
#define GLCD_D4_PIN DIO_PIN4
#define GLCD_D5_PIN DIO_PIN5
#define GLCD_D6_PIN DIO_PIN6
#define GLCD_D7_PIN DIO_PIN7

/*Other definitions*/
#define GLCD_TOTALPAGES 8

void GLCD_vidInit(void);
void GLCD_vidSendCommand(u8 u8CommandCpy);
void GLCD_vidWriteCharacter(u8 u8CharacterCpy);
void GLCD_vidWriteString(u8, u8 *);
void GLCD_vidClearAll(void);

#endif /* GLCD_INTERFACE_H_ */