#include <stdio.h>

enum weak {
	saturday,
	sunday,
	monday,
	wednesday,
	thursday,
	friday
};

void main() {
	enum weak today;
	today = monday;
	printf("Today is %d\n",today);
}
