#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "bubble_sort.h"

#include "utils.h"
#include "tests.h"

unsigned int ARRAY_SIZES[N_SIZES] = { 10, 100, 1000, 10000, 100000 };

/*
	Description:
		Determines if an array is ordered in ascending order.

*/
bool is_ordered(int arr[], unsigned int size)
{
	/* By definition an element is sorted with itself */
	if (size == 1)
		return true;

	/* At least more than one element */
	unsigned int i = 1;
	while (i < size)
	{
		if (arr[i] < arr[i - 1])
			return false;
		i++;
	}
	return true;
}

double time_sort_function(sort_function func_ptr, int arr[], unsigned int size, unsigned long long *n_iters)
{
	clock_t processing_clocks;
	double processing_time;

	/* RECORD TIME AT THE START (Start stopwatch) */
	processing_clocks = clock();

	/* Call the sort function */
	func_ptr(arr, size, n_iters);

	/* RECORD TIME AT THE END (Stop stopwatch) */
	processing_clocks = clock() - processing_clocks;

	/* CONVERT TO APPROPRIATE TIME UNIT, for example, seconds */
	processing_time = (double)processing_clocks / CLOCKS_PER_SEC;

	return processing_time;
}

void test_sort_functions(int *test_arrays[N_MEASUREMENTS][N_SIZES])
{
	function_t functions[N_SORT_FUNCTIONS] = {
		FUNC_DEF(selection_sort),
		FUNC_DEF(insertion_sort),
		FUNC_DEF(merge_sort),
		FUNC_DEF(bubble_sort)
	};

	/* evaluate each sort function */
	for (int i = 0; i < N_SORT_FUNCTIONS; i++)
	{
		printf("Testing the %s() function\n", functions[i].name);

		/* Do multiple measurements */
		for (int j = 0; j < N_MEASUREMENTS; j++)
		{
			printf("\nMEASURE %d\n", j);

			/* For different array sizes */
			for (int k = 0; k < N_SIZES; k++)
			{
				/* Number of iterations of inner loop or recursive calls */
				unsigned long long n_iters = 0;

				/* Array size */
				unsigned int size = ARRAY_SIZES[k];

				/* Crete a copy of the original random array as we don't want to modify it */
				int *array_copy = intdup(test_arrays[j][k], size);

				/* Call the sort function and measure its time */
				double time_elapsed = time_sort_function(functions[i].func_ptr, array_copy, size, &n_iters);

				/* Check if array sorted correctly */
				bool ok = is_ordered(array_copy, size);

				printf("array size: %6d\ttime elapsed: %f s\tn_iters: %10llu\ttest ok? %s\n", size, time_elapsed, n_iters, ok ? "true": "false");

				free(array_copy);
			}
		}
	}
}
