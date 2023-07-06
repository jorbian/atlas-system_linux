#include "task0.h"

static void magic_bytes(char *ls);
static void class(char *ls);
static void endianness(char *ls);
static void version(char *ls);

/**
 * print_header - Print the elf header
 * @ls: The first byte of the file
 *
 * Return: void
*/
void print_header(char *ls)
{
	magic_bytes(ls);
	class(ls);
	endianness(ls);
	version(ls);

	getOSABI((unsigned char)ls[EI_OSABI]);
	labelPrint("ABI Version:");
	printf("%u\n", (unsigned char)ls[EI_ABIVERSION]);

	if ((unsigned char)ls[EI_CLASS] == ELFCLASS64)
		print_elf_64bit(ls);
	else if ((unsigned char)ls[EI_CLASS] == ELFCLASS32)
		print_elf_32bit(ls);
}

/**
 * magic_bytes - Print the elf header magic bytes
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void magic_bytes(char *ls)
{
	int i;

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ls[EI_MAG0 + i]);

	printf("\n");
}

/**
 * class - Print the elf header class
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void class(char *ls)
{
	if ((unsigned char)ls[EI_CLASS] == ELFCLASS64)
		printf("  Class:%*s", 35, "ELF64\n");
	else if ((unsigned char)ls[EI_CLASS] == ELFCLASS32)
		printf("  Class:%*s", 35, "ELF32\n");
	else
		printf("  Class:%*s", 35, "Invalid class\n");
}

/**
 * endianness - Print the endianness of the file
 * @ls: The first byte of the file
 * Return: void
*/
static void endianness(char *ls)
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

/**
 * version - Print the elf header version
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void version(char *ls)
{
	if ((unsigned char)ls[EI_VERSION] == EV_CURRENT)
		lineItemPrint("Version:", "1 (current)");
	else if ((unsigned char)ls[EI_VERSION] == EV_NONE)
		lineItemPrint("Version:", "Invalid version");
	else
		lineItemPrint("Version:", "Unknown version");
}
