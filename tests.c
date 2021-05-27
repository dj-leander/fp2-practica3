#include <stdbool.h>
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