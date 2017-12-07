#include <stdio.h>
#include <stdlib.h>

int i,j,arSize;
int temp;
void doInsertionSort(int, int *);
void showArray(int, int *);

void main(void) {
	printf("Enter size:\n");
	scanf(" %d",&arSize);
	int ar[arSize];
	/*generate Array*/
	for (i = 0; i < arSize;i++) {
		ar[i] = rand()%arSize+1;
	}
	/*show Array*/
	showArray(arSize,ar);
	printf("\n");
	doInsertionSort(arSize,ar);
}

void doInsertionSort(int arSize, int * ar) {
	int x;
	for (x = 0; x < arSize; x++) {
		for(j= x+1; j > 0; j--) {
			if(ar[j] < ar[j-1]) {
				temp = ar[j-1];
				ar[j-1] = ar[j];
				ar[j] = temp;
			}
		}
		showArray(arSize,ar);
	}
}

void showArray(int arSize, int * ar) {
	for(i = 0; i < arSize; i++) {
		printf("%d ",ar[i]);
	}
	printf("\n");
}
