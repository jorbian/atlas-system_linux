#ifndef _MULTITHREADING_H
#define _MULTITHREADING_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_entry(void *arg);
int tprintf(char const *format, ...);
void mutex_constructor(void) __attribute__((constructor));
void mutex_destructor(void) __attribute__((destructor));

#endif
