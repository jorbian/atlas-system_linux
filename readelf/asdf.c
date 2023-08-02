#include <stdlib.h>
#include <stdio.h>

#include "LIEF/LIEF.h"
#include "helf.h"

static void print_identity(Elf_Header_t header);

int main(int argc, const char** argv) {

	Elf_Binary_t *elf_binary = elf_parse("./test/exec/netbsd32");
	Elf_Header_t elf_header = elf_binary->header;


	print_header(elf_binary);

	elf_binary_destroy(elf_binary);
}

static void print_identity(Elf_Header_t header)
{
	size_t i = 0;
	
	printf("  Magic:   ");

	for (i = 0; i < LIEF_ELF_EI_NIDENT; i++)
	{
		printf("%02x", header.identity[LIEF_ELF_EI_MAG0 + i]);

		if ((i + 1) != LIEF_ELF_EI_NIDENT)
			printf(" ");
	}
	printf("\n");
}

static void print_class(Elf_Binary_t *binary)
{
	char class_type[3][8] = {
		"unknown",
		"ELF32",
		"ELF64"
	};
	char field_name[8] = "  Class:";
	char padding[40] = "                             ";

	printf("%s%s%s\n", field_name, padding, class_type[binary->type]);
}

void print_header(Elf_Binary_t *binary)
{
	printf("ELF Header:\n");
	print_identity(binary->header);
	print_class(binary);
}