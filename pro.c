#include <stdio.h>

char x;
void main() {
	x = 'A';
	for(x; x < 'Z'; x++) {
	printf("%c = %d\n",x,x);
	}
}
