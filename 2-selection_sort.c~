#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * selection sort algorithm
 * @array: an array of integers
 * @size: side of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t minimum, i, j;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum])
				minimum = j;
		}
		if (i != minimum)
		{
			swap = array[i];
			array[i] = array[minimum];
			array[minimum] = swap;
			print_array(array, size);
		}
	}
}
