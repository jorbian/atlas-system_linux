#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1 "HOLBERTON SCHOOL"
#define S2 ""
#define S3 "\0"

/**
* main - Program entry point
*
* Return: EXIT_SUCESS or EXIT_FAILURE
*/
int main(void)
{
	assert(strlen(S1) == asm_strlen(S1));
	assert(strlen(S2) == asm_strlen(S2));
	assert(strlen(S3) == asm_strlen(S3));

	printf("ALL GOOD!\n");
	return (EXIT_SUCCESS);
}

