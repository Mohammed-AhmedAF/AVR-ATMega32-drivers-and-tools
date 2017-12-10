#include <stdio.h>

typedef struct strct{
	int x;
	int y;
	} groups;

typedef struct strct2{
	int a;
	int b;
} groups2;

void main() {
	groups group;
	groups2 group2;
	group.x = 10;
	group2.a = 20;

	printf("Vaue of groub: %d\n",group.x);
	printf("Value of group2: %d\n",group2.a);
}
