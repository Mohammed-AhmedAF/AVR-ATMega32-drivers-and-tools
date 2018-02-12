#include <stdio.h>

typedef unsigned char u8;
typedef signed char s8;

void main(void) {
	u8 c = '1';
	int i = c - 48;	
	printf("%d\n",i);
	c = '+';
	if (c == '+') {
		printf("It is working.\n");
	}
}
