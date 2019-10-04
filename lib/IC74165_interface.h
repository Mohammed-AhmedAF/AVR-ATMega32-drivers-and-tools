/*
 * IC74165_interface.h
 *
 * Created: 7/21/2019 8:32:46 AM
 */ 


#ifndef _IC74165_INTERFACE_H_
#define _IC74165_INTERFACE_H_

#define IC74165_SHLD_PORT DIO_PORTB
#define IC74165_SHLD_PIN DIO_PIN1
#define IC74165_CLKINH_PORT DIO_PORTB
#define IC74165_CLKINH_PIN DIO_PIN0

typedef struct  {
	u8 u8CLKINH_Port : 4;
	u8 u8CLKINH_Pin : 4;
	u8 u8SHLD_Port : 4;
	u8 u8SHLD_Pin : 4;
	}IC165_t;


void IC74165_vidInit(void);
void IC74165_vidInitExtended(IC165_t *);
u8 IC74165_u8GetByte(void);
u8 IC74165_u8GetByteExtended(IC165_t *);



#endif /* IC74165_INTERFACE_H_ */
