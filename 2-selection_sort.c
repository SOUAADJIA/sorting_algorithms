#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin;
	int temp;

	/* advance the position through the entire array */
	for (i = 0; i < size - 1; i++)
	{
		/* assume the min is the first element */
		jMin = i;
		/* test against elements after i to find the smallest */
		for (j = i + 1; j < size; j++)
		{
			/* if this element is less, then it is the new minimum */
			if (array[j] < array[jMin])
			{
				/* found new minimum; remember its index */
				jMin = j;
			}
		}
		if (jMin != i)
		{
			/* swap the found minimum element with the first element */
			temp = array[i];
			array[i] = array[jMin];
			array[jMin] = temp;
			print_array(array, size);
		}
	}
}
