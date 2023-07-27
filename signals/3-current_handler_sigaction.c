#include "signals.h"

/**
* current_handler_sigaction - retrieves current handler of SIGINT
*
* Return: pointer to current handler of SIGINT
*/
void (*current_handler_sigaction(void))(int)
{
	struct sigaction prev_action;

	memset(&prev_action, 0, sizeof(prev_action);

	if (sigaction(SIGINT, NULL, &prev) == -1)
		return (NULL);

	return (prev.sa_handler);
}

}
