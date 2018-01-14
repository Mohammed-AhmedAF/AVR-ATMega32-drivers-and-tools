#include <stdio.h>

typedef unsigned char u8;
typedef signed char s8;

void main(void) {
	u8 num;
	u8 u8Password[3] = {'a','b','c'};
	u8 u8UserPass[10];

	printf("Enter password:\n");
	for (s8 i = 0; i < 3; i++) {
		scanf(" %c",&num);
		u8UserPass[i] = num;
	}

	for (s8 i = 0; i < 3; i++) {
		if (u8Password[i] != u8UserPass[i]) {
			printf("Error!\n");
		}
	}
}
