#include "my_strings.h"

/**
 * _strdup - reimplementation of _strdup
 * @old_string: string that needs to be copied
 *
 * Return: pointer to the start of new string
*/
char *_strdup(const char *old_string)
{
	char *new_string;

	size_t length;

	if (old_string == NULL)
		return (NULL);

	length = _strlen(old_string) + 1;
	new_string = malloc(length);

	if (new_string != NULL)
		_memcpy(new_string, old_string, length);

	return (new_string);
}

/**
 * _strcmp - case insensitive reimplementation of _strcmp
 * @str1: first string to look at
 * @str2: second string to look at
 *
 * Return: the place where they start to differ
*/
int _strcmp(const char *str1, const char *str2)
{
	int diff;

	while (*str1 && *str2)
	{
		diff = TOLOWER((unsigned char)*str1) - TOLOWER((unsigned char)*str2);
		if (diff != 0)
			return (diff);
		str1++;
		str2++;
	}
	return (TOLOWER((unsigned char)*str1) - TOLOWER((unsigned char)*str2));
}

/**
 * _strlen - returns the length of a string
 * @s: the string we are counting the characters of
 *
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int n;

	for (n = 0; s[n]; n++)
		;
	return (n);
}

/**
 * _memcpy - reimplementation of memcpy (courtsety of ChatGPT)
 * @destination: Pointer to destination where the memory will be copied to.
 * @source: Pointer to the source from where the memory will be copied.
 * @num: Number of bytes to be copied
 *
 * Return: a pointer the the newly filled in memory.
*/
void *_memcpy(void *destination, const void *source, size_t num)
{
	size_t i;

	char *dest = (char *)destination;
	const char *src = (const char *)source;

	for (i = 0; i < num; i++)
		dest[i] = src[i];

	return (destination);
}

/**
 * _strcpy - reimplementation of strcpy (courtsety of ChatGPT)
 * @dest: place we're putting the copy
 * @src: where we're copying the string from
 *
 * Description: I want to use fixed buffers a few places and so I needed
 * this. I also needed to make sure the null character ends up on end.
*/
void _strcpy(char *dest, const char *src)
{
	size_t length = _strlen(src) + 1;

	_memcpy(dest, src, length);

	dest[length - 1] = '\0';
}
