#include <stdio.h>


/* A simple code to illustrate the properties of unions in C.*/

union test {
	int x;
	int y;
};

void main(void) {
	union test t;
	t.x = 10;
	printf("X equals %d, Y equals %d\n",t.x,t.y);

	t.y = 11;
	printf("X equals %d. Y equals %d\n",t.x,t.y);
}
