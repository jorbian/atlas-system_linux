#include "hls.h"

/**
 * *_strcpy - copies src string to dest
 * @dest: destination memory
 * @src: string to copy terminated by \0
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int iter = 0;

	if (!dest || !src)
		return (NULL);
	for (; src[iter]; iter++)
		dest[iter] = src[iter];
	dest[iter] = '\0';
	return (dest);
}

/**
 * _strcmp - compares 2 strings & shows value upon reaching difference
 * @str1: string 1
 * @str2: string 2
 * Return: value of difference
 */

int _strcmp(char *str1, char *str2)
{
	int iter = 0;

	if (!str1 || !str2)
		return (-1);
	while (str1[iter] == str2[iter] && (str1[iter] || str2[iter]))
		iter++;
	iter = (str1[iter] - str2[iter]);
	return (iter);
}

/**
 * _strlen - returns length of input string
 * @str: string to find length
 * Return: number of characters in string
 */

int _strlen(char *str)
{
	int iter = 0;

	if (!str)
		return (-1);
	for (; str[iter]; iter++)
		;
	return (iter);
}

/**
 * _strdup - duplicates string str & returns pointer to the duplicate
 * @str: object string
 * Return: pointer to duplicate of str
 */

char *_strdup(char *str)
{
	char *copy = NULL;
	int iter_1 = 0, iter_2 = 0;

	if (!str)
		return (NULL);
	iter_2 = _strlen(str) + 1;
	copy = malloc(sizeof(char) * iter_2);
	if (!copy)
		return (NULL);
	for (; iter_1 < iter_2; iter_1++)
		copy[iter_1] = str[iter_1];
	return (copy);
}

/**
 * _strcat - concatenates 2 strings
 * @dest: string 1 to have src appended to end
 * @src: string 2 to append to end of dest
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int iter_1 = _strlen(dest), iter_2 = 0;

	if (!dest || !src)
		return (NULL);
	for (; src[iter_2]; iter_1++, iter_2++)
		dest[iter_1] = src[iter_2];
	dest[iter_1] = '\0';
	return (dest);
}
