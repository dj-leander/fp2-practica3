#include <stdio.h>

#include "quick_sort.h"
#include "utils.h"

/*
*	Description:
*		Returns the position of the pivot element. 
*/
unsigned int partition(int arr[], unsigned int l, unsigned int r)
{
	int pivot = arr[r];		/* The last element is used as pivot */

	unsigned int i = l;		/* left search pointer */
	unsigned int j;			/* right search pointer */

	/*
	 * In each loop iteration, a new element of index j is processed,
	 * and all processed elements <= pivot are kept to the left, with indices < i.
	 */
	for (j = l; j < r; j++)
		if (arr[j] <= pivot)
			/* First swap, then increment i */
			swap(&arr[i++], &arr[j]);

	/*
	 * By swapping pivot A[r] with A[i], now all elements <= pivot are kept to the left,
	 * with indices <= i, and all elements > pivot are kept to the right.
	 * Placing the pivot in position i allows skipping it during recursive sorting.
	 */
	swap(&arr[i], &arr[r]);

	/* Return index i of pivot, now stored as A[i]. */
	return i; 
}

/* Description:
*		Order an array by dividing it in two parts. The left section whose
*		elements are all smaller than a pivot and the right section with
*		the large ones. The mentioned pivot is the last element.
*		This proccess is repeated until the sections have one element.
*		Because one element by definition is sorted.
*/
 void quick_sort_aux(int arr[], unsigned int l, unsigned int r, unsigned long long *n_iters)
{
	 if (l < r) {
		 /* Increment the # of times this function is accessed */
		 ++*n_iters;

		 unsigned int pivot_pos = partition(arr, l, r);

		 /* Pivot must be higher that leftmost index */
		 if (pivot_pos > l)
			quick_sort_aux(arr, l, pivot_pos - 1, n_iters);

		quick_sort_aux(arr, pivot_pos + 1, r, n_iters);
	 }
}
 
/*
 * Wrapper to call quick sort
*/
 void quick_sort(int arr[], unsigned int size, unsigned long long* n_iters)
 {
	 quick_sort_aux(arr, 0, size - 1, n_iters);
 }