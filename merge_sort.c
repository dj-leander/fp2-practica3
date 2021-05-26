#include <stdio.h>
#include <stdlib.h>

/*
 * Merges two subarrays:
 * 
 * arr[l..m] and arr[m+1..r]
 */
void merge(int arr[], unsigned int l, unsigned int m, unsigned int r)
{
    /* Size of the left subarray L[l..m] */
    unsigned int n1 = m - l + 1;

    /* Size of the right subarray R[m+1..r] */
    unsigned int n2 = r - m;

    /* Create temporary arrays L[] and R[] */
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        printf("Couldn't allocate memory");
        exit(EXIT_FAILURE);
    }

    /* Copy data to temporary arrays */
    for (unsigned int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (unsigned int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /*
     * Index of R subarray, index of L subarray and index of main array,
     * to where the subarrays will be merged.
     */
    unsigned int i = 0, j = 0, k = l;

    /*
     * Loop until we reach either end of either L or R subarray.
     * 
     * Pick the larger element among elements of L and R and place it
     * in the correct position of the original array at arr[l..r]
     */
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /*
     * At this point we run out of elements in either L or R, 
     * so let's pick up them and put in arr[k..r]
     */

    /* Copy the remaining elements of L[], if there are any */
    for (; i < n1; i++, k++)
        arr[k] = L[i];

    /* Copy the remaining elements of R[], if there are any */
    for (; j < n2; j++, k++)
        arr[k] = R[j];

    /* Free memory */
    free(L);
    free(R);
}

/*
 * Merge Sort recursive implementation
 * 
 * Sorts an array from left index l to right index r
 */
void merge_sort_aux(int arr[], unsigned int l, unsigned int r, unsigned long long *n_iters)
{
    /*
     * Do nothing if array contains a single element or it is empty.
     * (base case, sorted by definition)
     */
    if (l < r)
    {
        /*
         * Incremet the number of iterations only if the function does something
         * (in this case, recursive calls)
         */
        ++*n_iters;

        /* m is where the array is divided into two subarrays */
        unsigned int m = (l + r) / 2;

        /* Sort the subarrays */
        merge_sort_aux(arr, l, m, n_iters);
        merge_sort_aux(arr, m + 1, r, n_iters);

        /* Merge the sorted subarrays */
        merge(arr, l, m, r);
    }
}

/*
 * Wrapper to call merge sort
 */
void merge_sort(int arr[], unsigned int size, unsigned long long *n_iters)
{
    /* Sort from 0 to size-1 */
    merge_sort_aux(arr, 0, size - 1, n_iters);
}
