#include "vector.h"

/*
 * Sorts an array of specified size using election sort iterative algorithm
 * 
 * Also count the total number of interations of the inner loop,
 * n_iters parameter passed by reference
 */
void selection_sort(int arr[], unsigned int size, unsigned long long *n_iters)
{
    unsigned int i, j;

    /* Iterate through the the entire array except the last element */
    for (i = 0; i < size - 1; i++)
    {
        /* Assume the min is the first element */
        int jMin = i;

        /* Find the min element in the unsorted array */
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[jMin])
            {
                /* Found new minimum, remember its index */
                jMin = j;
            }

            /* Increment n_iters inside inner loop for analytic purposes */
            ++*n_iters;
        }

        /* Swap actual element with the minumum found */
        if (jMin != i)
        {
            swap(&arr[i], &arr[jMin]);
        }
    }
}