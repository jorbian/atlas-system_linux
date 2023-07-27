#include <stdio.h>
#include <stdlib.h>

/**
* current_handler_signal - gets the current handler of SIGINT
*
* Return: pointer to current handler of SIGINT, or NULL on failure
*/
void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, SIG_IGN);

	if (handler == SIG_ERR)
		return (NULL);

	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);

	return (handler);
}

