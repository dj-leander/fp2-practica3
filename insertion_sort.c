
/*
	Description:
		Arrange an array of specific size. It does this by building 
		a sorted array one item at a time. Starting from the second 
		element of the list.  

		It also counts the number of operations performed by the inner
		loop. This parameter is passed by reference.
*/
void insertion_sort(int arr[], unsigned int size, unsigned long long *n_iters)
{
	/* Starts at position 1 assuming one element is ordered by definition */
	for (unsigned int i = 1; i < size; i++)
	{
		int elem2sort = arr[i];

		/* Places the elem2sort at the right position in the ordered array */
		unsigned int j = i;
		for (; j > 0 && elem2sort < arr[j - 1]; j--)
		{
			arr[j] = arr[j - 1];	
			++*n_iters;	/* Updates how many times is entered in this loop */
		} 
		arr[j] = elem2sort; 
	}
}