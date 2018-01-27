#include <stdio.h>

int callCounter(void);

void main(void) {
	int x =	callCounter();
	printf("%d",x);
}

int callCounter(void) {
	int i;
	for (i = 0; i < 10; i++) {
		return i;
	}
	printf("This will not run\n");
}
