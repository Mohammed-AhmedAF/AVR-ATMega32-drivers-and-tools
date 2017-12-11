#include <stdio.h>

typedef unsigned char u8;

void main() {
	u8 character;
	character = 'A';
	for (character; character < 200; character++) {
		printf("%d\n",character);
	}
}
