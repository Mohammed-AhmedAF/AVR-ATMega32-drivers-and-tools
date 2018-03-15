#ifndef _PASSWORD_INTERFACE_H
#define _PASSWORD_INTERFACE_H
void Password_vidEnterID(void);
void Password_vidShowID(u8);
void Password_vidSave(u8);
void Password_vidSavePassword(u8,u8);
void Password_vidEnterPassword(void);
void Password_vidRetreiveID(u8);
void Password_vidReenterPassword(void);
u8 Password_vidCheckPasswordMatch(u8);
void Password_vidReadPassword(u8,u8);
void Password_vidCheckID(void);
u8 Password_vidCheckPassword(void);
#endif
