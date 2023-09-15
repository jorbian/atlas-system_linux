#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>

#include "syscalls.h"

static void fatal_error(char *error_msg);

/**
 * fatal_error - prints error and ends process
 * @error_msg: message to print when exiting
*/
static void fatal_error(char *error_msg)
{
	fprintf(stderr, "ERROR: %s\n", error_msg);
	exit(EXIT_FAILURE);
}

/**
 * main - Forks child process that is ptraced
 * @argc: Number of args
 * @argv: Filepath of the executable to possess child
 * @envp: environmental variables of process
 *
 * Return: Whether or not there was a problem.
 */
int main(int argc, char **argv, char **envp)
{
	pid_t pid;
	struct user_regs_struct user_regs;
	int child_status = EXIT_FAILURE;
	size_t alternator = 0;

	if (argc < 2)
		fatal_error("No input programme provided");

	pid = fork();
	if (pid == -1)
		fatal_error("Fork failed");
	else if (pid > 0)
	{
		puts("execve");
		while (!WIFEXITED(child_status))
		{
			alternator++;
			ptrace(PTRACE_SYSCALL, pid, 0, 0);
			wait(&child_status);

			if (
				ptrace(PTRACE_GETREGS, pid, 0, &user_regs) == 0 &&
				(alternator % 2 == 0)
			)
			{
				printf("%s", syscalls_64_g[user_regs.orig_rax].name);
				if (user_regs.orig_rax != 1)
					printf("\n");
			}
			if (user_regs.orig_rax == 1 && alternator % 2 == 1)
				printf("\n");

			fflush(stdout);
		}
		ptrace(PTRACE_DETACH, pid, NULL, NULL);
	}
	else if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, pid, 0, 0);
		execve(argv[1], &argv[1], envp);
	}
	return (EXIT_SUCCESS);
}
