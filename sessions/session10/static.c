#include <stdio.h>

typedef short int u16;

u16 x;

u16 sum(void);

void main() {
	x = sum();
	printf("Second call..\n");
	x = sum();
	printf("%d\n",x);
}

u16 sum(void) {
	 u16 y = 1;
	y++;
	return y;
}
