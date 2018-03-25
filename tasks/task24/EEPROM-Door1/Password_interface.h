#ifndef _PASSWORD_INTERFACE_H
#define _PASSWORD_INTERFACE_H
void Password_vidAskID(void);
void Password_vidShowID(u8);
void Password_vidSaveID(u8);
void Password_vidSavePassword(u8,u8);
void Password_vidAskPassword(void);
void Password_vidRetreiveID(u8);
void Password_vidReenterPassword(void);
u8 Password_vidCheckPasswordMatch(u8);
void Password_vidReadPassword(u8,u8);

#endif
