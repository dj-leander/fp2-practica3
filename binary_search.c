#include "stdio.h"
#include "binary_search.h"

/*
	Description:
		Looks for a number in a sorted array. It applies the binary search
		algorithm
	Parametres:
		- arr[] : sorted array to analyze
		- size : size of the array
	Results:
		Returns the position where the target number is || -1 in case the number
		doesn't exist.
*/
int binary_search(int arr[], unsigned int size, int target, unsigned long long *n_iters)
{
	int start, mid, end, mid_value;

	start = 0;
	end = size - 1;

	while (start <= end)
	{
		++ *n_iters;

		mid = (start + end) / 2;

		/*printf("\nlow = %d\tmid = %d\thigh = %d\ttarget = %d\n", low, mid, high, target);*/

		mid_value = arr[mid];

		if (target == mid_value)
			return mid;
		if (target > mid_value)
			start = mid + 1;
		else
			end = mid - 1;
	}

	/* If number not found return -1 */
	return -1;
}
