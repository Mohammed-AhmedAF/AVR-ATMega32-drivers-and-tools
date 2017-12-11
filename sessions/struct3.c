#include <stdio.h>

enum days {
	sat = 10,sun,mon,teus,wed,thrus,fri
};

void main() {
	enum days today;
	today = mon;
	int i;
	for (i = today ; today <20; today++)
		printf("Today is %d\n",today);
}
