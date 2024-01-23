#include "./inc/ZZstring.h"

/**
 * index_of - finds the first occurance of a character in a string
 * @p: string to search for the character in
 * @ch: the character being searched for in the string
 *
 * Return: Index of the first occurence of the character
*/
uint32_t index_of(char *p, int ch)
{
	char c, *q;

	c = ch;
	q = p;

	for (;; ++q)
	{
		if (*q == c)
			return (q - p);
		if (*q == '\0')
			return (-1);
	}
}

/**
 * ZZstrncpy - stupid reimplemenation of strcpy
 * @dst: where you're putting the string
 * @src: where you're getting it from
 * @n: limit of number of bytes to be copied
 * 
 * Return: pointer to the new string.
*/
char *ZZstrncpy(char *dst, const char *src, size_t n)
{
	if (n != 0)
	{
		register char *d = dst;
		register const char *s = src;

		do {
			if ((*d++ = *s++) == 0) {
				/* NUL pad the remaining n-1 bytes */
				while (--n != 0)
					*d++ = 0;
				break;
			}
		} while (--n != 0);
	}
	return (dst);
}
