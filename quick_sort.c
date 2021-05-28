#include <stdio.h>

#include "quick_sort.h"
#include "utils.h"

/*
*	Description:
*		Returns the position of the pivot element. 
*/
int partition(int arr[], int left, int right)
{
	int pivot = arr[right];		/* The last element is used as pivot */

	int i = left;		/* left search pointer */
	int j = right - 1;	/* right search pointer */

	// printf("i = %2u j = %2u\t", i, j);

	while (i < j)
	{
		/* Find the first element >= pivot */
		while (i < right - 1 && arr[i] < pivot )	/* If current element is < pivot */
			i++;				/* Move to the next element */
		
		/* Find the first element < pivot */
		while (j > left && arr[j] >= pivot)	/* If current element is >= pivot */
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
 void quick_sort_aux(int arr[], int left, int right, int long long *n_iters)
{
	 if (left >= right)
		 return;

	 /* Increment the # of times this function is accessed */
	 ++*n_iters;

	 /* 
	 printf("\n");
	 print_partial_array(arr, left, right);
	 printf("\tleft = %2u right = %2u\t", left, right);
	*/

	 int pivot_pos = partition(arr, left, right);
	 // printf("pivot_pos = %u", pivot_pos);
	 quick_sort_aux(arr, left, pivot_pos - 1, n_iters);
	 quick_sort_aux(arr, pivot_pos + 1, right, n_iters);
}
 
/*
*		
*/
 void quick_sort(int arr[], unsigned int size, unsigned long long* n_iters)
 {
	 quick_sort_aux(arr, 0, size - 1, n_iters);
 }