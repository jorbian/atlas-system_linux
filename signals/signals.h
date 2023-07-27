#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exist(pid_t pid);

#endif
