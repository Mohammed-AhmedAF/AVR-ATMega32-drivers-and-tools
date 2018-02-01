#include <stdio.h>

union test {
	int x;
	int y;
};


void main(void) {
	union test t1;
	union test * p1;
	p1 = &t1;
	p1->x = 78;
	printf("Member has value %d\n",p1->y);
}
