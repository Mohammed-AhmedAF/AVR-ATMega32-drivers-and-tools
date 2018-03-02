#include <stdio.h>

int i, j = 0;
int count;
int n, p,r,o;
int sum;
int power(int,int);
int root(int,int);
int root(int x, y) {
	
}

int main() {
	printf("Enter number:\n");
	scanf(" %d",&n);
	printf("Enter power:\n");
	scanf(" %d",&p);
	printf("--\n");
		sum = n;
		for (i = 1; i < n;i++) {
			r = power(i,p);
			sum = sum - r;
			printf("%d %d\n",i,sum);
			if (sum < 0) {
				break;
			}			
		}
}

int power(int x, int y) {
	int k = 1;
	for(j = 0; j <y; j++) {
		k *= x;
	}
	return k;
}
