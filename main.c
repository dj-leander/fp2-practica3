#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "utils.h"
#include "tests.h"

#define N_SIZES 5
#define N_SORTED 4

void main()
{
	/* Sizes of random arrays for testing purposes */
	unsigned int array_sizes[N_SIZES] = { 10, 100, 1000, 10000, 100000 };

	/* Sizes of sorted arrays for testing purposes */
	unsigned int sorted_array_sizes[N_SORTED] = { 10, 20, 100, 1000 };

	/* Random arrays */
	int *test_arrays[N_SIZES][N_MEASUREMENTS];

	/* Sorted arrays */
	int *sorted_arrays[N_SORTED][N_MEASUREMENTS];

	/* Initialize random number generator*/
	srand((unsigned int)time(NULL));

	printf("Testing sort algorithms with random vectors\n");
	printf("Generating random vectors...\n\n");

	/* Create random arrays */
	for (int i = 0; i < N_SIZES; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			test_arrays[i][j] = random_vect(array_sizes[i]);

	printf("Starting the tests...\n\n");

	/* Test sort functions with random arrays */
	test_sort_functions(test_arrays, array_sizes, N_SIZES);

	printf("Finished testing.\n");

	printf("Freeing memory...");

	/* Free memory */
	for (int i = 0; i < N_SIZES; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			free(test_arrays[i][j]);

	printf("Done.\n\n");

	printf("Testing	with sorted vectors.");
	printf("Generating sorted vectors...\n\n");

	/* Create sorted arrays */
	for (int i = 0; i < N_SORTED; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			sorted_arrays[i][j] = sorted_vector(sorted_array_sizes[i]);

	printf("Starting the tests...\n\n");

	/* Test sort functions with random arrays */
	test_sort_functions(sorted_arrays, sorted_array_sizes, N_SORTED);

	printf("Finished testing.\n");

	printf("Freeing memory...");

	/* Free memory */
	for (int i = 0; i < N_SORTED; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			free(sorted_arrays[i][j]);
}
