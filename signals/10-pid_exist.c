#include <sys/types.h>
#include <signal.h>

/**
 * pid_exist - does the given PID exist?
 * @pid: a process id
 * 
 * Return: 0 for for no, 1 for yes
*/
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) == 0);
}
