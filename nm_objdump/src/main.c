#include <stdio.h>
#include <stdlib.h>

#include "LIEF/LIEF.h"
#include "helf.h"

static int is_bad_file(const char *filename);
static int not_enough_args(int argc, int min_num);

/**
 * main - the entry point for the program
 * @argc: the number of args
 * @argv: the arguments
 *
 * Return: always 0
*/
int main(int argc, char **argv)
{
	if (not_enough_args(argc, 1) || is_bad_file(argv[1]))
	{
		printf("Usage: %s <elf_file>\n", argv[0]);
		return (1);
	}

	no_sort(argv[1]);

	return (0);
}

/**
 * is_bad_file - makes sure file exists AND it can be accessed
 * @filename: the filename/path we're checking
 *
 * Return:  1 for 'Yes' (it's bad) -- 0 for 'No' (it's good) --
*/
static int is_bad_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file != NULL)
	{
		fclose(file);
		return (0);
	}
	else
		return (1);
}

/**
 * not_enough_args - test to see program was given enough args
 * @argc: argc as passed directly from main
 * @min_num: the minimum number of args program needs
 *
 * Return: 1 for 'Yes' (there weren't enough) -- 0 for 'No' (we're good) --
*/
static int not_enough_args(int argc, int min_num)
{
	return (argc == min_num);
}
