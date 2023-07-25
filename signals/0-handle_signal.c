#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "signals.h"

/**
 * handle_sigint - the actual signal handler
 *
 * Return: 0
*/
static void handle_sigint(int signum)
{
	printf("Gotcha! %d\n", signum);
}

/**
 * handle_signal - wrapper which lays out the handler for SIGINT
 *
 * Return: 0 on success, or -1 on error
*/
int handle_signal(void)
{
	sighandler_t handler = signal(SIGINT, handle_sigint);

	if (handler == SIG_ERR)
		return (-1);

	return (0);
}
