#include "my_strings.h"

/**
 * quick_sort - a reimplimented version of the qsort function from stdlib
 * @base: void pointer to the begining of an array
 * @len: the length of the array we're looking at
 * @element_size: how big the current element is in memory
 * @comp: comparioson being used.
 *
*/
void quick_sort(void *base, size_t len, size_t element_size,
	int (*comp)(const void *, const void *))
{
	size_t i, j;

	char *temp;
	char *arr = (char *)base;
	char *pivot = arr;

	if (len <= 1)
		return;

	i = 1;
	j = len - 1;

	while (i <= j)
	{
		while (i < len && comp(arr + i * element_size, pivot) <= 0)
			i++;
		while (j > 0 && comp(arr + j * element_size, pivot) >= 0)
			j--;

		if (i < j)
		{
			temp = malloc(element_size);

			_memcpy(temp, arr + i * element_size, element_size);
			_memcpy(arr + i * element_size, arr + j * element_size, element_size);
			_memcpy(arr + j * element_size, temp, element_size);

			free(temp);
		}
	}
	temp = malloc(element_size);
	_memcpy(temp, arr + j * element_size, element_size);
	_memcpy(arr + j * element_size, pivot, element_size);
	_memcpy(pivot, temp, element_size);
	free(temp);

	quick_sort((char *)base, j, element_size, comp);
	quick_sort(
		(char *)base + (j + 1) * element_size, len - j - 1, element_size, comp
	);
}

/**
 * string_comp - wrapper for _strcmp to correct pointers
 * @a: void pointer but to a string
 * @b: anoter void poitner, but to a string
 *
 * Return: Whatever the results of _strcmp once we recast the pointers is
*/
int string_comp(const void *a, const void *b)
{
	const char *str1 = *(const char **)a;
	const char *str2 = *(const char **)b;

	return (_strcmp(str1, str2));
}
