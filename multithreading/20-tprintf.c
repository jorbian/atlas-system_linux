#include "multithreading.h"

static pthread_mutex_t mutex_print;

static void mutex_constructor(void) __attribute__((constructor));
static void mutex_destructor(void) __attribute__((destructor));
/**
* mutex_constructor - initalize mutex function
*/
void mutex_constructor(void)
{
	if (pthread_mutex_init(&mutex_print, NULL))
	{
		printf("mutex initialization fail\n");
		exit(EXIT_FAILURE);
	}
}

/**
* mutex_destructor - deinits the mutex
*/
void mutex_destructor(void)
{
	if (pthread_mutex_destroy(&mutex_print))
	{
		printf("mutex destroy fail\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * tprintf - uses printf family to print out given formatted string
 * @format: format string for printed output, followed by vargs
 * 
 * Return: EXIT_SUCCESS (i.e. 0) or EXIT_FAILURE (i.e. 1)
 */
int tprintf(char const *format, ...)
{
	va_list args;
	pthread_t thread_num;

	va_start(args, format);

	if (!format)
	{
		printf("format string error");
		exit(EXIT_FAILURE);
	}

	if (pthread_mutex_lock(&mutex_print))
	{
		printf("mutex lock failed\n");
		exit(EXIT_FAILURE);
	}
	thread_num = pthread_self();

	printf("[%lu] ", thread_num);
	vprintf(format, args);

	if (pthread_mutex_unlock(&mutex_print))
	{
		printf("mutex unlock failed");
		exit(EXIT_FAILURE);
	}
	va_end(args);

	return (EXIT_SUCCESS);
}
