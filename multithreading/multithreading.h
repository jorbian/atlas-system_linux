#ifndef _MULTITHREADING_H
#define _MULTITHREADING_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <pthread.h>
#include <unistd.h>

#include "list.h"

typedef void *(*task_entry_t)(void *);

/**
 * enum task_status_e - Task statuses
 *
 * @PENDING: Task pending
 * @STARTED: Task started
 * @SUCCESS: Task successfully
 * @FAILURE: Task completed with issues
 */
typedef enum task_status_e
{
	PENDING = 0,
	STARTED,
	SUCCESS,
	FAILURE
} task_status_t;

/**
 * struct task_s - Executable task structure
 *
 * @entry:  Pointer to function to serve as task entry
 * @param:  Address to custom content passed to the entry function
 * @status: Task status -- default to PENDING
 * @result: Stores return value of entry function
 * @lock:   Task mutex
 */
typedef struct task_s
{
	task_entry_t    entry;
	void        *param;
	task_status_t   status;
	void        *result;
	pthread_mutex_t lock;
} task_t;


void *thread_entry(void *arg);
int tprintf(char const *format, ...);
list_t *prime_factors(char const *string);
task_t *create_task(task_entry_t entry, void *param);
void destroy_task(task_t *task);
void *exec_tasks(list_t const *tasks);

#endif
