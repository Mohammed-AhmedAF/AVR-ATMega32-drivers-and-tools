#include <stdio.h>
#include <stdbool.h>

/*Just testing*/

/*just adding a comment */

void add(int a, int b) {
	int c = a + b;
	printf("%d\n",c);
}

void multiply(int a,int b) {
	int c = a * b;
	printf("%d\n",c);
}

void viewHelp() {
	printf("This is how to use this program.\n");
	printf("a : add, m : multiply, h : help\n");
	printf("e : exit program.\n");
}

int main() {
	int a, b;
	bool cont = true;
	char operation;
	while(cont) {
		scanf("%d",&a);
		scanf("%d",&b);
		scanf(" %c",&operation);
		switch(operation) {
			case 'a':
				add(a,b);
				break;
			case 'm':
				multiply(a,b);
				break;
			case 'e':
				cont = false;
				break;
			case 'h':
				viewHelp();
				break;
			default :
				printf("Invalid command\n");
			}
	}
	return 0;
}
