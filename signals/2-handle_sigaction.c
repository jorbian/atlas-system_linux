#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * print_gotcha - print a message that a signal was received
 * @sig: the signal
 * Return: void
*/
void print_gotcha(int sig)
{
	printf("Gotcha! [%d]\n", sig);
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

	memset(&new_action, 0, sizeof(new_action));
	new_action.sa_handler = signal_handler;

	exit_status = sigaction(SIGINT, &handle, NULL);

	return (exit_status);
}

