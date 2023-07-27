#include "signals.h"

static void acknowledge_signal(int signal);
static int set_sigaction(void);

/**
* acknowledge_signal - print message that signal was received
* @signal: the signal number recieved
*
* Return: void
*/
static void acknowledge_signal(int signal)
{
	printf("Caught %d\nSignal received\n", signal);
}

/**
* set_sigaction - register signal using sigaction
*
* Return: the result of sigaction()
*/
static int set_sigaction(void)
{
	struct sigaction sig_action;

	sig_action.sa_handler = &acknowledge_signal;
	sig_action.sa_flags = SA_RESTART;

	return (sigaction(SIGINT, &sig_action, NULL));
}

/**
* main - entry point of program waits until to receive interrupt signal
*
* Return: zero
*/
int main(void)
{
	set_sigaction();
	pause();
	return (0);
}
