#include "sort.h"
#include <stdlib.h>

/**
* _calloc - ...
* @nmemb: number of members
* @size: size
*
* Return: ...
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
int i = 0, l = 0;
char *p;

if (nmemb == 0 || size == 0)
return (NULL);

l = nmemb * size;
p = malloc(l);

if (p == NULL)
return (NULL);

while (i < l)
{
p[i] = 0;
i++;
}

return (p);
}

void counting_sort(int *array, size_t size)
{
	int index, maximun = 0, *counter = '\0', *tmp = '\0';
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > maximun)
			maximun = array[i];
	counter = _calloc(maximun + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	
	for (index = 1; index <= maximun; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximun + 1);
	
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
