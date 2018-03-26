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
u8 Password_u8CheckPassword(void);
u8 Password_u8CheckSaveFlag(void);
void Password_vidSaveSize(void);
void Password_vidBlockUser(void);
u8 Password_u8CheckBlock(void);

#define PASSWORD_SAVED_PASSWORD_FLAG_LOCATION 40
#define PASSWORD_SAVED_FLAG 1
#define PASSWORD_UNSAVED_FLAG 0

#define PASSWORD_ID_SIZE_LOCATION 41
#define PASSWORD_PASSWORD_SIZE_LOCATION 42

#define PASSWORD_BLOCKED_FLAG_LOCATION 43

#define PASSWORD_BLOCKED 0
#define PASSWORD_NOT_BLOCKED 1

#endif
