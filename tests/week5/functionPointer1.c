#include <stdio.h>

void printMessage(void);

void printMessage(void) {
	printf("Printing a message.\n");
}

void main() {
	void (*fpPrintMessage) (void);
	(*fbPrintMessage) = &printMessage;
	fbPrintMessage;
}
