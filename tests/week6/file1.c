#include <stdio.h>

extern int x;

int i;

void main() {
	for (i = 0; i < x; i++) {
		printf("This is a message.\n");
	}
}
