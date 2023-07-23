#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - counting sort algorithm
 * @array: list to be sorted
 * @size: size of the input array
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int *output, max = 0, j = 0;
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{ max = array[i]; }
	}
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}
	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
	{ count[array[i]] += 1; }
	j = 1;
	while (j <= max)
	{
		count[j] = count[j] + count[j - 1];
		j++;
	}
	print_array(count, (max + 1));
	for (i = 0; i < size; i++)
	{
		output[count[array[i]]] = array[i];
		count[array[i]] = count[array[i]] - 1;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}
