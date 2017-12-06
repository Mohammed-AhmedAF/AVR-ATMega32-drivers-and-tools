#include <stdio.h>

void up(int b);
void down(int b);
void rightTipped(int h);
void leftTipped(int h);
void viewAll(int h);

int h = 0, i, b, x, s,j;

int main() {
	char type;
	printf("Enter no. of pyramid height: \n");
	scanf(" %d",&h);
	printf("(U)p or (D)own, (L)eft or (R)ight, or (A)ll\n");
	scanf(" %c",&type);
	if (type == 'u' || type == 'U')
			up(h);
	else if (type == 'd' || type == 'D') 
			down(h);
	else if (type == 'r' || type == 'R')
			rightTipped(h);
	else if (type == 'l' || type == 'L')
			leftTipped(h);
	else if (type == 'a' || type == 'A')
			viewAll(h);
	else 
		printf("Enter u, d, r or l\n");
}


void down(int h) {
	b = h*2-1;
	for(j = 0; j < h; j++) {
		/*space loop*/
		for(s = 0; s < j;s++) {
			printf(" ");
		}
		/*x loop*/	
		for(x = 1; x <= b-2*j; x++) {
			printf("x");
		}
		printf("\n");
	}
}

void up(int h) {
	b = 2*h+1;
	s = (b-2)/2;
	/*line loop*/
	for(j = 1; j <= h; j++){
	/*space loop*/
		for(i = s; i > 0; i--) {
			printf(" ");
		}
	/*block loop*/
		for(x = 1; x < j*2; x++) {
			if(j == 1) {
				printf("x");
				break;
			}
			else {
				printf("x");
			}
		}
		printf("\n");
		s--;
	}
}
void leftTipped(int h) {
	b = h*2+1;
	int z = h-1; /*to make an equation*/
	/*line loop*/
	for(i = 1; i <= h;i++) {
	/*space loop*/
		for(s = 1; s <= h-i; s++) {
			printf(" ");
		}
	/*x loop*/	
		for(x = 1; x <= i; x++) {
			printf("x");	
		}
		printf("\n");
	}	
	int l = 0;
	for(l = b-h; l >= 1; l--) {
	/*space loop*/	
			for(s = 1; s <= i-h; s++) {
				printf(" ");
			}
	/*block loop*/
			for(x =b-i; x > 1; x--) {
				printf("x");
			}
			i++;
			printf("\n");
		}
	}
		
void rightTipped(int h) {
	b = h*2-1;
	/*line loop*/
	for (i = 1; i <= h; i++) {
		/*block loop*/
		for(x = 1; x <= i; x++) {
			printf("x");
		}
		printf("\n");
	}
	int l = 0;
	for(l = b - h; l >= 1; l--) {
	/*block loop*/
		for(x = b-i+1; x>= 1; x--) {
			printf("x");
		}
	 	i++;
		printf("\n");
		}
	}
void viewAll(int h) {
	down(h);
	printf("\n");
	up(h);
	printf("\n");
	rightTipped(h);
	printf("\n");
	leftTipped(h);
}

