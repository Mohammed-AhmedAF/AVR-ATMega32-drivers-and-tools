#include <stdio.h>

/*Mohamed Ahmed Abd Al-Fatah
17-11-2017*/
void main() {
        int a, b;
        int addition, multiplication, division, substraction;
        printf("Enter the first number: \n");
        scanf("%d",&a);
        printf("Enter the second number: \n");
        scanf("%d",&b);
        addition = a + b;
        multiplication = a * b;
        division = a / b;
        substraction = a - b;
        printf("Addition: %d\n", addition);
        printf("Multiplication: %d\n",multiplication);
        printf("Division: %d\n", division);
        printf("Substraction: %d\n", substraction);
}

