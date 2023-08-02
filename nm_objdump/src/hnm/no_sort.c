#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helf.h"

static int is_32bit;

static void print_address(Elf_Symbol_t *symb);

void no_sort(const char *filename)
{
	size_t i, name_len;

	Elf_Binary_t *elf_binary = elf_parse(filename);
	Elf_Symbol_t **symtab = elf_binary->static_symbols;

	is_32bit = (elf_binary->type == 1);

	for (i = 0; symtab[i] != NULL; ++i)
	{
		name_len = strlen(symtab[i]->name);
		if (!name_len)
			continue;

		print_address(symtab[i]);
		
		printf("%s  %d\n",
			symtab[i]->name,
			symtab[i]->type
		);
	}

	elf_binary_destroy(elf_binary);
}

/**
 * print_address - prints the symbol address based on
 * system architecture.
*/
static void print_address(Elf_Symbol_t *symb)
{
	if (is_32bit)
		printf("%08lx", symb->value);
	else
		printf("%016lx", symb->value);
}

