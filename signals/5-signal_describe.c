#include "signals.h"

/**
* main - entry point for signal num program
* @argc: number of arguments program was invoked with
* @argv: the arguments stored in an array
*
* Return: Whether or not there was a problem
*/
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));

	return (EXIT_SUCCESS);
}
