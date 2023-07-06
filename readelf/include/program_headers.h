#ifndef PROGRAM_HEADERS_H
#define PROGRAM_HEADERS_H

#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>

int program_headr32(char *p);
int program_headrs64(char *p);


#endif /* TASK_2 */
