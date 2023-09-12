#ifndef _MULTITHREADING_H
#define _MULTITHREADING_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <pthread.h>
#include <unistd.h>
#include <pthread.h>

void *thread_entry(void *arg);
int tprintf(char const *format, ...);

#endif
