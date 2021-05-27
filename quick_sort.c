#include "quick_sort.h"
#include "utils.h"

/*
*	Description:
*		Returns the position of the pivot element. 
*/
unsigned partition(int arr[], unsigned left, unsigned right)
{
	int pivot = arr[right];		/* The last element is used as pivot */

	unsigned i = left;		/* left search pointer*/
	unsigned j = right - 1;	/* right search pointer*/

	while (i < j)
	{
		/* Find the first element >= pivot */
		while (arr[i] < pivot)	/* If current element is < pivot */
			i++;				/* Move to the next element */
		
		/* Find the first element < pivot */
		while (j > left && arr[j] >= pivot)	/* If current element is > pivot */
			j--;							/* Move to the next element */

		/* Place in the correct section the first major and minor number found */
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--; 
		} 
	}

	/* Move i to the right in order to mark the start of the right section */
	if (i == j && arr[i] < pivot)
		i++;

	/* Move pivot element to the center of sections */
	if (arr[i] != pivot)
		swap(&arr[i], &arr[right]);

	/* Return the position of pivot element */
	return i; 
}

/* Description:
*		Order an array by dividing it in two parts. The left section whose
*		elements are all smaller than a pivot and the right section with
*		the large ones. The mentioned pivot is the last element.
*		This proccess is repeated until the sections have one element.
*		Because one element by definition is sorted.
*/
 void quick_sort_aux(int arr[], unsigned left, unsigned right, unsigned long long *n_iters)
{
	 if (left < right)
		 return;

	 /* Increment the # of times this function is accessed */
	 ++*n_iters;

	 unsigned int pivot_pos = partition(arr, left, right);
	 quick_sort_aux(arr, left, pivot_pos - 1, n_iters);
	 quick_sort_aux(arr, pivot_pos + 1, right, n_iters);
}
 
/*
*		
*/
 void quick_sort(int arr[], unsigned size, unsigned long long *n_iters)
 {
	 quick_sort_aux(arr, 0, size - 1, n_iters);
 }