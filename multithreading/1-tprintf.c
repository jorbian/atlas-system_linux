#include "multithreading.h"

/**
* tprintf - function that uses printf family to print out given string.
* @format: string to print
*
* Return: EXIT_SUCCESS (i.e. 0) or EXIT_FAILURE (i.e. 1)
*/
int tprintf(char const *format, ...)
{
	unsigned long int calling_thread_id;

	if (format)
	{
		calling_thread_id = pthread_self();
		printf("[%lu] %s", calling_thread_id, format);
	}

	return (EXIT_SUCCESS);
}

