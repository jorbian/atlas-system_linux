#include "signals.h"

/**
* signal_handler - print message that signal was reieved
* @sig: the signal that was sent
* @sig_info: information about signal
* @vp: reserved
*
* Return: void
*/
static void signal_handler(int sig, siginfo_t *sig_info, void *vp)
{
	(void)sig;
	(void)vp;

	printf("SIGQUIT sent by %d\n", sig_info->si_pid);
}

/**
* trace_signal_sender - create handler to report which pid sent signal
*
* Return: 0 if sucess, -1 if fail
*/
int trace_signal_sender(void)
{
	struct sigaction new_action, old_action;

	new_action.sa_sigaction = signal_handler;

	sigemptyset(&new_action.sa_mask);

	new_action.sa_flags = SA_RESTART | SA_SIGINFO;

	if (sigaction(SIGQUIT, &new_action, &old_action) < 0)
		return (-1);

	return (0);
}

