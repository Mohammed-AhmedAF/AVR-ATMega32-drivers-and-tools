#include <stdio.h>
#include <string.h>

void doBinarySearch(int,int);
void createArray(void);
char answer[100];

int arr[99];
int search;
int end = 100;
int i;
void main() {
	printf("Do you want to create an array?\n");
	scanf(" %s",answer);
	if(strcmp("yes",answer) == 0) {
		createArray();
	}
	else {
		printf("Exiting...\n");
	}

	printf("What do you want to search for?\n");
	scanf("%d",&search);
	for(i = 0; i < end; i++) {
		arr[i]	= i;
	}
	printf("What do you want to search for?\n");
	doBinarySearch(end,search);
}

void createArray() {
	printf("Array created.\n");
}

void doBinarySearch(int end, int x) {
 	int mid;
	int start = 0;
	end = end -1;
	while(start <= end) {
		mid = (end)/2;
		if(x == arr[mid]) {
			printf("Index is %d\n", mid);
			break;
		}
		else if (x < arr[mid]) {
			end = end-1;
		}
		else {
			end = end+1;
		}
	}

}
