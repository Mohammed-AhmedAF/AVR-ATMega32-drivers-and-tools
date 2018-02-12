#ifndef PASSWORD_INTERFACE_H
#define PASSWORD_INTERFACE_H

u8 u8id[5];
u8 u8password[5];
u8 u8passwordTemp[5];

void Password_vidSavePassword(u8*,u8*);

struct user {
	u8 u8id[5];
	u8 u8password[6];
};
struct user db[10];

#define NO_MATCH "No match"
#define PASSWORD_SAVED "Password saved"
#define ID "ID: "
#define PASSWORD "Password: "
#define RE_PASSWORD "Reenter password: "
#endif
