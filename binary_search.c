#include "stdio.h"
#include "binary_search.h"
/*
	Description:
		Looks for a number in a sorted array. It applies the binary search
		algorithm
	Parametres:
		- arr[] : sorted array to analyze
		- low : lowest index position to start looking
		- high : highest index position to start looking
	Results:
		Returns the position where the target number is || -1 in case the number
		doesn't exist.
*/
int binary_search(int arr[], int low, int high, int target, unsigned long long *n_iters)
{
	unsigned int mid;
	int mid_value;
	while (low <= high)
	{
		++*n_iters;
		mid = (low + high) / 2;

		printf("\nlow = %d\tmid = %d\thigh = %d\ttarget = %d\n", low, mid, high, target);

		mid_value = arr[mid];
		if (target == mid_value) 
			return mid;
		if (target > mid_value) 
			low = mid + 1;
		else
			high = mid - 1;
	}
	/* If number not found return -1 */
	return -1;
}