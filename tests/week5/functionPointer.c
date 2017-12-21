#include <stdio.h>

int compare(int,int);

int a,b;
int res;

int (*fb) (int, int);

void main() {
	printf("Enter number a:\n");
	scanf(" %d",&a);
	printf("Enter number b:\n");
	scanf(" %d",&b);
	fb = &compare;
	res = (*fb)(a,b);
	printf("Result is %d\n",res);
}


int compare(int a, int b){
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return 2;
	}
	else {
		return 0;
	}

