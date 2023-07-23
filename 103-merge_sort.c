#include "sort.h"

/**
 * merge - The merge function, it merges two subarrays appropriately
 *
 * @partial: a subarray
 * @array: the array to be sorted
 * @start: start index
 * @mid: mid index
 * @end: end index
 * Return: void
 */
void merge(int *partial, int *array, size_t start, size_t mid, size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(partial + start, mid - start);

	printf("[right]: ");
	print_array(partial + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
	{
		if (partial[i] < partial[j])
		{
			array[k] = partial[i++];
		}
		else
		{
			array[k] = partial[j++];
		}
	}
	for (; i < mid; i++)
		array[k++] = partial[i];
	for (; j < end; j++)
		array[k++] = partial[j];
	for (i = start, k = 0; i < end; i++)
		partial[i] = array[k++];

	printf("[Done]: ");
	print_array(partial + start, end - start);
}

/**
 * recursion - the cursive function for splitting the array
 * @partial: partial or subarray
 * @array: the original array, not splitted
 * @start: start index
 * @end: end index
 * Return: void
 */
void recursion(int *partial, int *array, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = (start + end) / 2;
		recursion(partial, array, start, mid);
		recursion(partial, array, mid, end);
		merge(partial, array, start, mid, end);
	}
}

/**
 * merge_sort - merge sort function
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	recursion(array, copy, 0, size);
	free(copy);
}
