#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Mohamed Ahmed Abd Al-Fatah Mahmoud Kamel*/
/*Started on 20-11-2017*/

void eval (double result) {
	if (result > 0) {
		printf("Result is larger than 0.\n");
	}
	else if(result < 0) {
		printf("Result is less than 0.\n");
	}
	else {
		printf("Result is equal to zero.\n");
	}

	if ((int)result % 2 == 0) {
		printf("Result is even.\n");
	}
	else {
		printf("Result is odd.\n");
	}
}

int main() {
  char yesOrNo;
  int a, b;
  double c, doubleRes;
  int result;
  char operation, sign;
  char * bigSign =  malloc(sizeof(char)*2);
  printf("Do you want a calculator or not?\n");
  printf("y if yes, n if no\n");
  scanf("%c",&yesOrNo);
  if(yesOrNo == 'n')
  {
    return 0;
  }
  else if (yesOrNo == 'y') {
    printf("You can use this program to make 4 kinds of operations on 2 numbers.\n");
    printf("The operations are arithmatic, logical, relational and bitwise.\n");
    printf("After entering the 2 numbers, choose the operation you want by entering the first letter of it's name.\n");
    printf("Enter the first number:\n");
    scanf(" %d",&a);
    printf("Enter the second number:\n");
    scanf(" %d",&b);
    printf("Enter operation type: \n");
    scanf(" %c",&operation);
    switch(operation) {
	/*arithmatic operations*/
    	case 'a':
		printf("Enter operation sign:\n");
		scanf(" %c",&sign);
		switch (sign) {
			case '+':
				result = a + b;
				printf("Addition: %d\n", result);
				eval(result);
				break;
			case '-':
				result = a-b;
				printf("Substraction: %d\n",result);
				eval(result);
				break;
			case '*':
				result = a*b;
				printf("Multiplication: %d\n",result);
				eval(result);
				break;
			case '/':
				if (b == 0) {
					printf("You are dividing by zero.\n");
					printf("Can't calculate result.");
				}
				else {
					c = (double) a;
					doubleRes = c/b;
					printf("Division: %lf\n",doubleRes);
					eval(doubleRes);
				}
				break;
			default:
				printf("Invalid or unsupported sign\n");
		}
		break;
		/*logical operations*/
  	case 'l':
		printf("Enter logical sign:\n");
		scanf(" %s", bigSign);
		if(strcmp(bigSign,"&&") == 0) {
			result = a && b;
			printf("%d\n",result);
			eval(result);
		}
		else if(strcmp(bigSign,"||") == 0) {
			result = a || b;
			printf("%d\n",result);
			eval(result);
		}
		else {
			printf("Unsupported operation.\n");
		}
		break;
		/*bitwise operations*/
	case 'b':
		printf("Enter bitwise sign: \n");
		scanf(" %c",&sign);
		switch(sign) {
			case '&':
				result = a & b;
				printf("%d\n", result);
				eval(result);
				break;
			case '|':
				result = a | b;
				printf("%d\n",result);
				eval(result);
				break;
			case '^':
				result = a ^ b;
				printf("%d\n",result);
				eval(result);
				break;
			case '~':
				printf("~ is unary operator, choose which operand you want to use: a or b\n");
				scanf(" %c", &sign);		
				if (sign == 'a') {
					result = (~a);
					printf("%d\n",result);
					eval(result);
				}
				else {
					result = (~b);
					printf("%d\n",result);
					eval(result);
				}
				break;
			default:
				printf("Invalid operator!\n");
				break;
		}
		break;    
		/*relational operations*/
	case 'r':
			if(a < b) {
				printf("B is larger than A.\n");			}
			else if (a > b) {
				printf("A is larger than B.\n");
			}
			else {
				printf("A is equal to B.\n");
			}	
		break; 
	default:
		printf("Invalid operation letter.\n");
	}
}
else {
	printf("Wrong answer.\n");
	}
return 0;
}
