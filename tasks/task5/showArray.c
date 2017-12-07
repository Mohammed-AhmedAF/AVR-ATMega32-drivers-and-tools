#include <stdio.h>

void showArray(int arr[], int size) {
	int i;
	printf("-----\n");
	if (size <= 10) {
		for (i = 0; i < size; i++) {
			printf("%d ",arr[i]);
		}
	}
	else {
		int x = 0;
		int limit = 10;
		while(x < size) {
			for(i = 0; i < limit; i++) {
			printf("%d ",arr[i+x]);
			}
			printf("\n");
			x += 10;
		}
		
	}
}
