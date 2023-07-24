#include "sort.h"
#include <stddef.h>

/**
 * heap_sort - heap sort algorithm
 * @array: the array to sort
 * @size: the size or length of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	if (array == NULL || size < 2)
		return;
	i = (size / 2) - 1;
	while (i >= 0)
	{
		heapify(array, size, size, i);
		i--;
	}
	i = size - 1;
	while (i > 0)
	{
		temp = *array;
		*array = *(array + i);
		*(array + i) = temp;
		print_array(array, size);
		heapify(array, size, i, 0);
		i--;
	}
}

/**
 * heapify - convert tree to binary heap
 * @array: array of integers
 * @size: the size of te array
 * @base: index of base row
 * @root: root node of binary tree
 * Return: void
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;
	int temp;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		temp = *(array + root);
		*(array + root) = *(array + large);
		*(array + large) = temp;
		print_array(array, size);
		heapify(array, size, base, large);
	}
}
