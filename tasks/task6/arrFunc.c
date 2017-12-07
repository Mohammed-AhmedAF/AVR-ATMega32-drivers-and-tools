#include <stdio.h>
#include <stdlib.h>

int operation, sum, average, min, max;
int i,j,s;
int num,size,indx;
char caller;

void operateOnArray(int [], int);
void getAverage(int [], int);
void getMax(int [], int);
void getMin(int [], int);
int getSum(int [], int,char);
void showArray(int [], int);


int main() {
	int arr[100];
	printf("Enter array size: \n");
	scanf(" %d",&size);
	for (i = 0; i < size; i++) {
		arr[i] = rand()%size + 1;
	}
		while(1){
	operateOnArray(arr,size);
	}
}

void operateOnArray(int arr [], int size) {
	printf("Choose operation:\n");
	printf("1) Show array\n2) Get sum\n3) Get average\n4) Get max\n");
	scanf(" %d",&operation);
	switch (operation) {
		case 1:
			showArray(arr,size);
			break;
		case 2:
			getSum(arr,size,'o');
			break;
		case 3:
			getAverage(arr,size);
			break;
		case 4:
			getMax(arr,size);
			break;
		default:
			printf("Invalid operation\n");
	}
}

int getSum(int arr [], int size,char caller) {
	for (i = 0; i < size; i++) {
		sum = sum + arr[i];
	}
	if (caller == 'o') {
		printf("Sum is %d\n",sum);
		return 0;
	}
	else {
		return sum;
	}
}

void getAverage(int arr [], int size) {
	int s = getSum(arr,size,'a');
	average = s/size;
	printf("Average is %d\n",average);
}

void getMax(int arr [], int size) {
	max = arr[0];
	for(i = 1; i < size; i++) {
		if(max <arr[i]) {
			max = arr[i];
		}
	}
	printf("Max is %d\n",max);
}

void getMin(int arr [], int size) {
	min = arr[0];
	for (i = 1; i < size; i++) {
		if(min > arr[i]) {
			min = arr[i];
		}
	}
	printf("Min is %d\n",min);
}

void showArray(int arr [], int size) {
	for (i = 0; i < size; i++) {
		printf("%d ",arr[i]);
	}
}
