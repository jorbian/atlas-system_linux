#include "multithreading.h"

/**
* thread_entry - function that serves as entry point to new thread.
* @arg: holds address of a string to print
*
* Return: just void
*/
void *thread_entry(void *arg)
{
	if (!arg)
		pthread_exit(NULL);
	else
		printf("%s\n", (char *)arg);

	pthread_exit(NULL);
}
