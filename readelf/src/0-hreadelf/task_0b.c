#include "task0.h"

/**
 * is_elf - Check if the file is an ELF file
 * @ls: The first byte of the file
 * Return: void
*/

int is_elf(char *ls)
{
	if (
	(unsigned char)ls[EI_MAG0] == 0x7f &&
	(unsigned char)ls[EI_MAG1] == 'E' &&
	(unsigned char)ls[EI_MAG2] == 'L' &&
	(unsigned char)ls[EI_MAG3] == 'F'
	)
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}

/**
 * print_magic_bytes - Print the elf header magic bytes
 * @ls: The first byte of the file
 * Return: void
*/
void print_magic_bytes(char *ls)
{
	int i;

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ls[EI_MAG0 + i]);
	}
	printf("\n");
}

/**
 * print_elf_class - Print the elf header class
 * @ls: The first byte of the file
 * Return: void
*/

void print_elf_class(char *ls)
{
	if ((unsigned char)ls[EI_CLASS] == ELFCLASS64)
		printf("  Class:%*s", 35, "ELF64\n");
	else if ((unsigned char)ls[EI_CLASS] == ELFCLASS32)
		printf("  Class:%*s", 35, "ELF32\n");
	else
		printf("  Class:%*s", 35, "Invalid class\n");
}

/**
 * print_endianness - Print the endianness of the file
 * @ls: The first byte of the file
 * Return: void
*/

void print_endianness(char *ls)
{
	if ((unsigned char)ls[EI_DATA] == ELFDATA2LSB)
		printf("  Data:%*s%s", 30,
		 " ", "2's complement, little endian\n");
	else if ((unsigned char)ls[EI_DATA] == ELFDATA2MSB)
	{
		printf("  Data:%*s%s",
		 30, " ", "2's complement, big endian\n");
		/* ((Elf32_Ehdr *)ls)->e_entry; */
		doBigEndian();
	}
	else
		printf("  Data:%*s%s", 30, " ", "Unknown data format\n");
}
