#include <stdio.h>

void showArray(int arr [], int);

int i = 0,j = 0;
int x = 0;
int temp = 0;

void main() {
	int arr [10] = {10, 9, 8, 7, 6, 5, 4, 3, 2,1};
	int size = sizeof(arr)/sizeof(int);
	
	while(x < size-1) {
		while (i >= 0 && arr[i+1] < arr[i]) {
			temp = arr[i+1];
			arr[i+1] = arr[i];
			arr[i] = temp;
			i--;
		}
		printf("Run no %d ", x+1);
		showArray(arr,size);
		x++;
		i = x;
	}

}

void showArray(int arr [], int size) {
	for (j = 0; j< size; j++) {
		printf("%d ",arr[j]);
	}
	printf("\n");
}
