#include <stdio.h>

void main() {
	int found = 10;
	int index = -1;
	int holder = 0;
	int search;
	int arr[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int size = sizeof(arr)/sizeof(int);
	printf("Size of array: %d\n",size);
	printf("Enter a number to search\n");
	scanf(" %d",&search);
	int current = size/2;
	while(found) {
		holder = current;
		if(search == arr[current]) {
			found = 1;
			index = current;
			break;
		}
		else if(search > arr[current]){
			current = current+ current/2;
		}
		else if (search < arr[current]) {
			current = current-current/2;
		}
		if (current == 1 && holder == 1) {
			current = 0;
		}
		found--;
	}
	if (index == -1) {
		printf("Search element not found\n");
	}
	else {
		printf("Found it on %d \n",index);
	}

}
