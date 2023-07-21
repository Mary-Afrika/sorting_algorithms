#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts arrays of integers from min to max order
 * @array: array of unsorted integers
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t c;
	int temp;
	int did_swap;

	if (array == NULL || size == 0 || size == 1)
		return;

	for (c = 0; c  < size - 1; c++)
	{
		did_swap = 0;
		for (i = 0; i < size - c - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				did_swap = 1;
				print_array(array, size);
			}
		}
		if (!did_swap)
		{
			break;
		}
	}
}
