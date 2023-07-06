#ifndef TASK_0
#define TASK_0

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

#define SWAP(x) swapBytes(&x, sizeof(x))
#define PRINT_LABEL(label) (printf("  %-35s", label))
#define PRINT_LINE_ITEM(l, v) (printf("  %-35s%s\n", l, v))

void doBigEndian(void);
void swapBytes(void *pv, size_t n);
void getOSABI(unsigned char value);
void print_type64(char *ls);
void print_machine64(char *ls);
void print_elf_64bit(char *ls);
void print_elf_32bit(char *ls);
void print_type32(char *ls);
void print_machine32(char *ls);
void print_header(char *ls);

#endif /* TASK_0 */