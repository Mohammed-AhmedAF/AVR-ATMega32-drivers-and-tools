#ifndef _GLCD_INTERFACE_H
#define _GLCD_INTERFACE_H

/*GLCD port number definition*/

#define GLCD_D0_PORT DIO_PORTA
#define GLCD_D1_PORT DIO_PORTA
#define GLCD_D2_PORT DIO_PORTA
#define GLCD_D3_PORT DIO_PORTA
#define GLCD_D4_PORT DIO_PORTA
#define GLCD_D5_PORT DIO_PORTA
#define GLCD_D6_PORT DIO_PORTA
#define GLCD_D7_PORT DIO_PORTA

#define GLCD_RS_PORT DIO_PORTB
#define GLCD_RW_PORT DIO_PORTB
#define GLCD_EN_PORT DIO_PORTB

#define GLCD_RST_PORT DIO_PORTB
#define GLCD_PSB_PORT DIO_PORTD
#define GLCD_CS2_PORT DIO_PORTD


/*GLCD pin number definition*/
#define GLCD_D0_PIN DIO_PIN0
#define GLCD_D1_PIN DIO_PIN1
#define GLCD_D2_PIN DIO_PIN2
#define GLCD_D3_PIN DIO_PIN3
#define GLCD_D4_PIN DIO_PIN4
#define GLCD_D5_PIN DIO_PIN5
#define GLCD_D6_PIN DIO_PIN6
#define GLCD_D7_PIN DIO_PIN7


#define GLCD_RS_PIN DIO_PIN0
#define GLCD_RW_PIN DIO_PIN1
#define GLCD_EN_PIN DIO_PIN2

#define GLCD_RST_PIN DIO_PIN7
#define GLCD_PSB_PIN DIO_PIN1
#define GLCD_CS2_PIN DIO_PIN2

/*Definition of GLCD commands*/
#define GLCD_CLEARSCREEN 0x01
#define GLCD_RETURN_HOME 0x02
#define GLCD_DISPLAYON 0x0C
#define GLCD_DISPLAY_OFF 0x0B
#define GLCD_FUNCTIONSET 0x30
#define GLCD_ENTRYMODE 0x06

/*Function definitions*/
void GLCD_vidInit(void);
void GLCD_vidSendCommand(u8 u8Command);
void GLCD_vidWrite(u8 u8Data);
void GLCD_vidEnableGraphics(void);
void GLCD_vidDisbaleGraphics(void);
#endif
