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
	struct sigaction new_action, old_action;

	int exit_status = 0;

	new_action.sa_handler = print_gotcha;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;

	sigaction(SIGINT, NULL, &old_action);
	if (old_action.sa_handler != SIG_IGN)
		exit_status = (sigaction(SIGINT, &new_action, NULL));

	return (exit_status);
}

