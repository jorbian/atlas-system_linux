#include <sys/types.h>
#include <signal.h>

int process_exists(pid_t pid) {
    return (kill(pid, 0) == 0);
}
