#ifndef _PASSWORD_INTERFACE_H
#define _PASSWORD_INTERFACE_H
void Password_vidAskID(void);
void Password_vidShowID(u8);
void Password_vidSave(u8);
void Password_vidSavePassword(u8,u8);
void Password_vidAskPassword(void);
void Password_vidRetreiveID(u8);
void Password_vidReenterPassword(void);
u8 Password_vidCheckPasswordMatch(u8);
void Password_vidReadPassword(u8,u8);
void Password_vidModifyFlag(u8);
void Password_vidCheckFlag(void);
#define PASSWORD_FLAG_LOCATION 200
#define PASSWORD_FLAG_SET 1
#define PASSWORD_FLAG_UNSET 0

#endif
