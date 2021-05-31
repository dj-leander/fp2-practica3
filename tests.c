#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "quick_sort.h"

#include "utils.h"
#include "tests.h"

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

void test_sort_functions(int *test_arrays[][N_MEASUREMENTS], unsigned int array_sizes[], unsigned int n_arrays)
{
	function_t functions[N_SORT_FUNCTIONS] = {
		FUNC_DEF(selection_sort),
		FUNC_DEF(insertion_sort),
		FUNC_DEF(merge_sort),
		FUNC_DEF(bubble_sort),
		FUNC_DEF(quick_sort)
	};

	/* evaluate each sort function */
	for (unsigned int i = 0; i < N_SORT_FUNCTIONS; i++)
	{
		printf("Testing the %s() function\n\n", functions[i].name);

		/* For different array sizes */
		for (unsigned int j = 0; j < n_arrays; j++)
		{
			/* Array size */
			unsigned int size = array_sizes[j];

			printf("ARRAY SIZE: %d\n", size);

			/* Total time */
			double total_time = 0;

			/* Do multiple measurements */
			for (unsigned int k = 0; k < N_MEASUREMENTS; k++)
			{
				/* Number of iterations of inner loop or recursive calls */
				unsigned long long n_iters = 0;
				
				/* Crete a copy of the original random array as we don't want to modify it */
				int *array_copy = intdup(test_arrays[j][k], size);

				/* Call the sort function and measure its time */
				double time_elapsed = time_sort_function(functions[i].func_ptr, array_copy, size, &n_iters);

				total_time += time_elapsed;

				/* Check if array sorted correctly */
				bool ok = is_ordered(array_copy, size);

				printf("MEASURE: %d\ttime elapsed: %f s\tn_iters: %10llu\ttest ok? %s\n",
					k, time_elapsed, n_iters, ok ? "true" : "false");

				free(array_copy);
			}

			printf("total time: %f s\taverage: %f s\n\n", total_time, total_time / N_MEASUREMENTS);
		}
	}
}
