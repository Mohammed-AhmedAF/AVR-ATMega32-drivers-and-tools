#include <stdio.h>

/*Mohamed Ahmed Abd Al-Fattah Mahmoud*/
/*Finished on 28-11-2017*/

void drawSide(char);
void drawUp();
void drawDown();
void build(int,char);
void draw(int);

int sideBlocks, downBlocks, upBlocks;
int numberOfLines, lineNumber;
char requester;
int counter;
int height;

int main() {
	printf("Enter height:\n");
	scanf(" %d",&height);
	draw(height);
}

void draw(int height) {
	upBlocks = height*2-1;
        sideBlocks = 0;
	downBlocks = 1 ;
	lineNumber = 1;
	numberOfLines = height*2+1;

	while(lineNumber <= numberOfLines) {
		if(lineNumber <= height) {
			drawSide('l');
			drawUp();
			drawSide('r');
		}
		else {
			drawSide('l');
			drawDown();
			drawSide('r');
		}
		lineNumber++;
	}
}

void drawUp() {
	build(upBlocks,'u');
	upBlocks -= 2;
}

void drawDown() {
	if(lineNumber == height+1)
		downBlocks = 1;
	else {
		build(downBlocks,'d');
		downBlocks +=2;
	}
}

void drawSide(char side) {
	build(sideBlocks,side);
	if(side == 'r') {
		if(lineNumber == 1) 
			sideBlocks = 1;	
		else if (lineNumber == height)
			sideBlocks += 1;
		else if (lineNumber > height)
			sideBlocks -= 1;
		else
			sideBlocks += 1;
	}
}

void build(int blocks, char requester) {
	for(counter = blocks; counter > 0; counter--)
		printf("*");
	if (requester == 'l' || requester == 'u' || requester == 'd') 
		printf(" ");
	else if(requester == 'r')
		printf("\n");
}
