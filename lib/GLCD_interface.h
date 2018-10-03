#ifndef _GLCD_INTERFACE_H

#define GLCD_CE_PORT
#define GLCD_RESET_PORT
#define GLCD_DC_PORT
#define GLCD_DIN_PORT

#define GLCD_CE_PIN 7
#define GLCD_RESET_PIN 6
#define GLCD_DC_PIN 5
#define GLCD_DIN_PIN 4
#define GLCD_CLK_PIN 3
#define GLCD_C LOW
#define GLCD_D HIGH


void GLCD_vidInit(void);
void GLCD_vidWrite(u8,u8);
#endif
