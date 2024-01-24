#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./inc/hls.h"

/**
 * check_for_dot - check for the dot and adjust accordingly
 * @s: string to check
 *
 * Return: Pointer to the string.
*/
static char *check_for_dot(char *s)
{
	if (FIRST_CHAR(s) == 46 && IS_ALPHANUM(NTH_CHAR(s, 1)))
	{
		s++;
	}
	return (s);
}

/**
 * string_compare - forward strings to naive_strcmp
 * @v1: first string
 * @v2: second string
 *
 * Return: Which needs to appear first
*/
int string_compare(void *v1, void *v2)
{
	char *a1 = *(char **)v1;
	char *a2 = *(char **)v2;

	a1 = check_for_dot(a1);
	a2 = check_for_dot(a2);

	return (naive_strcmp(a1, a2));
}

/**
 * swap - swap two elements of array being sorted
 * @v1: pointer to first element
 * @v2: pointer to second element
 * @size: how big the elements are in memory
*/
static void swap(void *v1, void *v2, int size)
{
	char buffer[size];

	memcpy(buffer, v1, size);
	memcpy(v1, v2, size);
	memcpy(v2, buffer, size);
}

/**
 * quick_sort - sort an array of elements
 * @v: pointer to the array that's being sorted
 * @size: how big the elemnts are supposed to be
 * @left: start
 * @right: end
 * @comp: pointer to the function being used to compare elements
*/
void quick_sort(void *v, int size, int left, int right,
					  int (*comp)(void *, void *))
{
	void *vt, *v3;
	int i, last, mid = (left + right) / 2;

	if (left >= right)
		return;

	void *vl = (char *)(v + (left * size));
	void *vr = (char *)(v + (mid * size));

	swap(vl, vr, size);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		vt = (char *)(v + (i * size));
		if ((*comp)(vl, vt) > 0)
		{
			++last;
			v3 = (char *)(v + (last * size));
			swap(vt, v3, size);
		}
	}
	v3 = (char *)(v + (last * size));
	swap(vl, v3, size);
	quick_sort(v, size, left, last - 1, comp);
	quick_sort(v, size, last + 1, right, comp);
}
