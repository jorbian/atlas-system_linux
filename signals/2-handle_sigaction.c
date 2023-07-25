#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * handle_sigint - the actual signal handler
 * @signum: enum value associated with the signal
 *
*/
void handle_sigint(int signum)
{
	printf("Gotcha! [%d]\n", signum);
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

	new_action.sa_handler = handle_sigint;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;

	sigaction(SIGINT, NULL, &old_action);
	if (old_action.sa_handler != SIG_IGN)
		exit_status = (sigaction(SIGINT, &new_action, NULL));

	return (exit_status);
}

