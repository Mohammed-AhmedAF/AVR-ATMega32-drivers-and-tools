#include <stdio.h>

void main(void) {
	int x = 2, y = 3, z = 0;
	printf("%d\n",(x||y));
	printf("%d\n",(x&&y));
	printf("%d\n",(x||z));
	printf("%d\n",(x&&z));
	printf("%d\n",((x&&z)||2));
	printf("%d\n",(!((x&&z)||2)));
}
