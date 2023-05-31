#include "main.h"

/**
 * _strnlen - returns the length of a string
 *
 * @s: the string we are counting the characters of
 * @max: the maximum number of characters to count
 * Return: the length of the string
 */
int _strnlen(char *string, int max)
{
	int length = 0;

	if (max < 0)
		max = INT_MAX;
	while (*string != '\0' && length < max)
	{
		string++;
		length++;
	}
	return (length);
}

/**
 * _strndup - Returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 * @str: the string to copy
 * @max: the maximum number of characters to copy
 * Return: the address of the copied string, NULL if failed
 */

char *_strndup(char *str, int maxlen)
{
	int x = 0;
	int size = 0;
	char *new_string;

	if (str == NULL)
		return (NULL);

	size  = _strnlen(str, maxlen);
	new_string = malloc(size * sizeof(char) + 1);
	if (new_string == NULL)
		return (NULL);

	while (x < size)
	{
		*(new_string + x) = *(str + x);
		x++;
	}
	*(new_string + x) = '\0';
    
	return (new_string);
}
