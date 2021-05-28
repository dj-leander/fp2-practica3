#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#define MAX 100000

/*
 * Allocates a vector of specified size and fills it with random numbers.
 *
 * Returns a pointer to allocated memory.
 * 
 * size must not exceed MAX and it cannot be 0.
 */
int *random_vect(unsigned int size)
{
	if (size > MAX || size == 0)
		return NULL;

	/* Allocate memory */
	int *arr = (int *)malloc(size * sizeof(int));

	/* Check if malloc not returned NULL */
	if (!arr)
	{
		printf("Couldn't allocate memory\n");
		exit(EXIT_FAILURE);
	}

	/* Fill the array with random numbers */
	for (unsigned int i = 0; i < size; i++)
		*(arr + i) = rand();

	return arr;
}

/*
 * Duplicates int array of specified size
 * 
 * Returns a pointer to allocated memory on succes or NULL on failure
 */
int *intdup(int *src, unsigned int size)
{
	int *a = (int *)malloc(size * sizeof(int));

	/* Check if malloc not returned NULL */
	if (a == NULL)
	{
		printf("Couldn't allocate memory\n");
		exit(EXIT_FAILURE);
	}

	memcpy(a, src, size * sizeof(int));

	return a;
}

/* This function swaps values pointed by a and b */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* Prints an array on the screen */
void print_partial_array(int arr[], unsigned int l, unsigned int r)
{
	printf("[ ");
	// for (; l <= r; l++)
	while (l <= r)
	{ 
		printf("%d ", arr[l]);
		l++;
	}
	printf("]");
}

void print_entire_array(int arr[], unsigned int size)
{
	printf("\n[ ");
	for (unsigned int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("]");
}
