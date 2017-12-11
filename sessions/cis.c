#include <stdio.h>

struct str {
	int x;
	int y;
}str_a, str_b,str_sum;

struct str * addStruct(struct str, struct str);
void main() {
	str_a.x = 10;
	str_a.y = 12;
	
	str_b.x = 12;
	str_b.y = 17;

	struct str * p;
	p = addStruct(str_a,str_b);

	if ( p->y < 0)	{
		printf("Sum is %d %di\n",p->x,p->y);
	}
	else
		printf("Sum is %d + %di",p->x,p->y);
}

struct str * addStruct(struct str str_a, struct str str_b) { 
	str_sum.x = str_a.x + str_b.x;
	str_sum.y = str_a.y + str_b.y;
	struct str * p;
	p = &str_sum;
	return p;
}
