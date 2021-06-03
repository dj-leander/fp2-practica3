#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "quick_sort.h"
#include "utils.h"
#include "tests.h"
#include "test_binary_search.h"

/* Number of different sizes of random vectors */
#define N_SIZES 9

/* Number of different sizes of sorted vectors */
#define N_SORTED 4

/* Number of different sizes of arrays for binary search tests */
#define N_SEARCH_SIZES 11

void main()
{
	/* Initialize random number generator*/
	srand((unsigned int)time(NULL));

	/******************** TEST SORT WITH RANDOM ARRAYS ***********************/

	/* Sizes of random arrays for testing purposes */
	unsigned int array_sizes[N_SIZES] = { 10, 100, 1000, 10000, 20000, 40000, 60000, 80000, 100000 };

	/* Random arrays */
	int *test_arrays[N_SIZES][N_MEASUREMENTS];

	printf("Testing sort algorithms with random vectors\n");
	printf("Generating random vectors...\n\n");

	/* Create random arrays */
	for (int i = 0; i < N_SIZES; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			test_arrays[i][j] = random_vect(array_sizes[i]);

	printf("Starting the tests...\n\n");

	/* Test sort functions with random arrays */
	test_sort_functions(test_arrays, array_sizes, N_SIZES);

	printf("\nFinished testing.\n");
	printf("Freeing memory...\n");

	/* Free memory */
	for (int i = 0; i < N_SIZES; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			free(test_arrays[i][j]);

	printf("Done.\n\n");

	/******************** TEST SORT WITH SORTED ARRAYS ***********************/

	/* Sizes of sorted arrays for testing purposes */
	unsigned int sorted_array_sizes[N_SORTED] = { 10, 20, 100, 1000 };

	/* Sorted arrays */
	int *sorted_arrays[N_SORTED][N_MEASUREMENTS];

	printf("Testing	sort algorithms with sorted vectors.\n");
	printf("Generating sorted vectors...\n\n");

	/* Create sorted arrays */
	for (int i = 0; i < N_SORTED; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			sorted_arrays[i][j] = sorted_vector(sorted_array_sizes[i]);

	printf("Starting the tests...\n\n");

	/* Test sort functions with sorted arrays */
	test_sort_functions(sorted_arrays, sorted_array_sizes, N_SORTED);

	printf("\nFinished testing.\n");
	printf("Freeing memory...\n");

	/* Free memory */
	for (int i = 0; i < N_SORTED; i++)
		for (int j = 0; j < N_MEASUREMENTS; j++)
			free(sorted_arrays[i][j]);

	printf("Done.\n\n");

	/************************* TEST BINARY SEARCH ****************************/

	unsigned int search_array_sizes[N_SEARCH_SIZES] = { 7, 50, 100, 1000, 2000, 5000, 10000, 25000, 30000, 50000, 100000 };

	/* Arrays for the binay search tests */
	int *search_arrays[N_SEARCH_SIZES][N_SEARCHES];

	printf("Testing	binary search.\n");
	printf("Generating random vectors and sorting them...\n\n");

	/* Generate random vectors and sort them */
	for (int i = 0; i < N_SEARCH_SIZES; i++)
		for (int j = 0; j < N_SEARCHES; j++)
		{
			unsigned long long n_iters = 0;

			/* Generate a random vector */
			search_arrays[i][j] = random_vect(search_array_sizes[i]);

			/* Sort it with quicksort */
			quick_sort(search_arrays[i][j], search_array_sizes[i], &n_iters);
		}

	printf("Starting binary search tests...\n\n");

	/* Test binary search with generated vectors */
	test_binary_search(search_arrays, search_array_sizes, N_SEARCH_SIZES);

	printf("\nFinished testing.\n");
	printf("Freeing memory...\n");

	/* Free memory */
	for (int i = 0; i < N_SEARCH_SIZES; i++)
		for (int j = 0; j < N_SEARCHES; j++)
			free(search_arrays[i][j]);

	printf("Done.\n");
}
