#include "sort.h"

/**
 * quick_sort_hoare - quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_partition - subset of an array of integer
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: end index of the subset to order.
 * Return: final partition index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below, temp;

	pivot = array[right];
	above = left - 1;
	below = right + 1;

	while (above < below)
	{
		while (array[++above] < pivot)
			;
		while (array[--below] > pivot)
			;
		if (above < below)
		{
			temp = *(array + above);
			*(array + above) = *(array + below);
			*(array + below) = temp;
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * hoare_sort - recursive quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * @left: start index of the array
 * @right: end index of the array
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int section;

	if (right - left > 0)
	{
		section = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, section - 1);
		hoare_sort(array, size, section, right);
	}
}
