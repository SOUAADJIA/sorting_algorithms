#include "sort.h"

/**
 * calculate_gap - Calculates the initial gap using Knuth sequence
 * @size: Size of the array
 * Return: Initial gap value
 */
size_t calculate_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	return (gap);
}

/**
 * shell_sort - Sorts an array of integers using Shell sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	gap = calculate_gap(size);
	if (array == NULL || size < 2)
		return;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
