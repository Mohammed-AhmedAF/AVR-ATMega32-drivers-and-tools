/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief code file for week1 assinments
 *
 * This code file has the definition of the array and function calls
 * of the first assinment of the course Introduction to Embedded Systems
 * on Coursera.
 *
 * @author Mohamed Ahmed Abd Al-Fattah Mahmoud Kamel
 * @date 26-12-2017
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
unsigned char sum = 0;
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
	unsigned int size = SIZE;
	unsigned char * p = test;
	print_statistics(p,size);
}

/* Add other Implementation File Code Here */
void print_array(unsigned char * test, unsigned int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ",*(test+i));
	}
}

void sort_array(unsigned char * ptest,unsigned int size) {
	/*Sorting using bubble sort*/
	unsigned char temp;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size-1; j++) {
			if(*(ptest+j) < *(ptest+j+1)) {
				temp = *(ptest+j);
				*(ptest+j) = *(ptest+j+1);
				*(ptest+j+1) = temp;
			}
		}
	}
}
unsigned char find_maximum(unsigned char * ptest, unsigned int size) {
	sort_array(ptest,size);
	return *ptest;
}

unsigned char find_minimum(unsigned char * ptest, unsigned int size) {
	sort_array(ptest,size);
	return *(ptest+size-1);
}

unsigned char find_mean(unsigned char * ptest, unsigned int size) {
	unsigned int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (int)*(ptest+i);
	}
	unsigned int mean = sum/size;
	return (unsigned char) mean;
}

unsigned char find_median(unsigned char * ptest, unsigned int size) {
	sort_array(ptest,size)
	return *(ptest+size/2) + *(ptest+size/2+1);
}

void print_statistics(unsigned char * ptest, unsigned int size) {
	sort_array(ptest,size);
	printf("\nMaximum is %d\n",find_maximum(ptest,size));
	printf("Minimum is %d\n",find_minimum(ptest,size));
	printf("Mean is %d\n",find_mean(ptest,size));
	printf("Median is %d\n",find_median(ptest,size));
	print_array(ptest,size);
}
