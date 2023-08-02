#include <stdlib.h>
#include <stdio.h>

#include "LIEF/LIEF.h"
#include "helf.h"

int main(int argc, const char** argv) {

	Elf_Binary_t *elf_binary = elf_parse("./test");
	Elf_Header_t elf_header = elf_binary->header;

	print_identity(elf_header);

	elf_binary_destroy(elf_binary);
}

void print_identity(Elf_Header_t header)
{
	size_t i = 0;

	while (i++ < LIEF_ELF_EI_NIDENT)
		printf("%02x ", header.identity[LIEF_ELF_EI_MAG0 + i]);
}
