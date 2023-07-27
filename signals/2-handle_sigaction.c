#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "signals.h"

/**
 * handle_sigint - print a message that a signal was received
 * @sig: the signal
 * Return: void
*/
void handle_sigint(int my_sig)
{
	printf("Gotcha! [%i]\n", my_sig);
	fflush(stdout);
}

/**
 * handle_sigaction - adsf asdf adfs
 *
 * Return: void.
*/
int handle_sigaction(void)
{
	struct sigaction new_action;

	int exit_status = 0;

	new_action.sa_handler = &handle_sigint;
	new_action.sa_flags = SA_RESTART;

	exit_status = sigaction(SIGINT, &new_action, NULL);

	return (exit_status);
}
