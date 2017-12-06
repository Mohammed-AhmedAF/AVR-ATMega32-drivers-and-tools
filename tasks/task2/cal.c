#include <stdio.h>

/*24-11-2017*/
/*The purpose of this program is to take two numbers from the user
and then ask the user for the operation to be done on the two numbers:
(A)ddition or (S)ubstraction.

Then we ask the user if he/she wants to continue using the program or
want to quit, using a yes or no question.

We ask for a confirmation of quiting.
 */


void main() {
	char cont = 'y', internal = 'y', exe= 'y';
	char operation;
	int a, b, res;
	while (exe=='y') {
		printf("Enter first number: \n");
		scanf(" %d",&a);
		printf("Enter second number: \n");
		scanf(" %d",&b);
		while(1) {
		printf("(A)dition or (S)ubstraction: \n");
		scanf(" %c",&operation);
			if(operation == 'a' || operation == 'A') {
				res = a + b;
				printf("Result is %d.\n",res);
				break;
			}
			else if (operation == 's' || operation == 'S') {
				res = a - b;
				printf("Result is %d.\n",res);
				break;
			}
			else 	{
				printf("Invalid operataion.\n");
				printf("Enter a or s, A or S\n");
			}
		}
		internal == 'y';
		while(internal == 'y') {
			printf("Do you want to continue?");
			scanf(" %c",&cont);
			if(cont == 'y' ||  cont == 'Y') {
				break;
			}
			else if(cont == 'n' || cont == 'N') {
				printf("Are you sure?\n");
				scanf(" %c",&cont);
				if(cont == 'y' || cont =='Y'){
					exe = 'n';
					break;
				}
				else if (cont == 'n' || cont == 'N') {
					break;
				}	
				else {
					printf("Please enter n or N, y or Y\n");
				}
			}
			else {
				printf("Please enter n or N, y or Y only.\n");
			}
		}
	}
}

