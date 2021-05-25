#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

/*
 * Allocates a vector of specified size and fills it with random numbers.
 *
 * Returns a pointer to allocated memory on succes or NULL on failure.
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
		arr[i] = rand();

	return arr;
}

// This function swaps values pointed by a and b
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}