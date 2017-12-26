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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/*
 * @brief prints the stats of the given array
 *
 * This function takes as input a pointer to the array,
 * and the size, it then gives the parameters to the
 * functions that actually find those statistics.
 *
 *@param ptest pointer to the array
 *@param size size of array
 *
 *@return void	
*/
void print_statistics(unsigned char *, unsigned int);
/*
*@brief Prints the contetns of array
*
*This function takes as input a pointer to the array
*and it's size, then it prints the contents of that array.
*
*@param ptest pointer to the array
*@param size size of array
*
*@return void
*/
void print_array(unsigned char *,unsigned int);
/*
*@brief sorts the array in descending order
*
*This function takes as input two parameters, a pointer to
* the array, and size. It sorts the array in descending order
* using bubble sort.
*
*@param ptest pointer to the array
*@param size size of the array
*
*@return void
*/
void sort_array(unsigned char *,unsigned int);
/*
*@brief Find the maximum value in the array
*
*This function takes as input two parameters, the pointer to the array
*and the size. It find the maximum value in the array, provided that
*the array has been sorted.
*
*@param ptest pointer to the array
*@param size size of the array
*
*@return the maximum value
*/
unsigned char find_maximum(unsigned char *, unsigned int);
/*
*@brief Finds the minimum value in the array
*
*This function finds the minimum value in the given array
*provided that the array has been sorted.
*
*@param ptest pointer to the array 
*@param size size of the array
*
*@return the minimum value
*/
unsigned char find_minimum(unsigned char *, unsigned int);
/*
*@brief	Finds the mean value in the array
*
*This function finds the mean value in the array, by summing the contents
*of the array and dividing the result by the number of those contents, which
*is the size.
*
*@param ptest pointer to the array
*@param size the size of the array
*
*@return the mean value
*
*/
unsigned char find_mean(unsigned char *, unsigned int);
/*
*@brief Finds the median value in the array
*
*The function finds the median value in the array, by summing the contents in 
*the middle of the array after it has been sorted.
*
*@param ptest pointer to the array
*@param size size of the array
*
*@return the median value
*/
unsigned char find_median(unsigned char *, unsigned int);
#endif /* __STATS_H__ */
