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
u8 Password_u8CheckID(void);
u8 Password_vidCheckPassword(void);
u8 Password_u8CheckSaveFlag(void);

#define PASSWORD_SAVED_PASSWORD_FLAG_LOCATION 200
#define PASSWORD_SAVED_FLAG 1
#define PASSWORD_UNSAVED_FLAG 0
#endif
