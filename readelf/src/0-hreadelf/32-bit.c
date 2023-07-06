#include "elf_headers.h"

static void type32(char *ls);
static void machine32(char *ls);
static void entryp32(char *ls);

/**
 * print_elf_32bit - Print the elf header info
 * @ls: The first byte of the file
 *
 * Return: void
*/
void print_32bit(char *ls)
{
	type32(ls);
	machine32(ls);
	entryp32(ls);
	PRINT_LABEL("Start of program headers:");
	printf("%u (bytes into file)\n", ((Elf32_Ehdr *)ls)->e_phoff);
	PRINT_LABEL("Start of section headers:");
	printf("%u (bytes into file)\n", ((Elf32_Ehdr *)ls)->e_shoff);
	PRINT_LABEL("Flags:");
	printf("0x");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_flags);
	PRINT_LABEL("Size of this header:");
	printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_ehsize);
	PRINT_LABEL("Size of program headers:");
	printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_phentsize);
	PRINT_LABEL("Number of program headers:");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_phnum);
	PRINT_LABEL("Size of section headers:");
	printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_shentsize);
	PRINT_LABEL("Number of section headers:");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_shnum);
	PRINT_LABEL("Section header string table index:");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_shstrndx);
}

/**
 * type32 - Print the elf type
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void type32(char *ls)
{
	PRINT_LABEL("Type:");
	if (ET_CORE == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
		printf("CORE (Core file)\n");
	else if (ET_EXEC == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
		printf("EXEC (Executable file)\n");
	else if (ET_REL == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
		printf("REL (Relocatable file)\n");
	else if (ET_DYN == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
		printf("DYN (Shared object file)\n");
	else if (ET_NONE == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
		printf("Unknown type\n");
	else
		printf("Something weird\n");
}

/**
 * machine32- Print the elf machine info
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void machine32(char *ls)
{
	PRINT_LABEL("Machine:");
	if (EM_386 == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
		printf("Intel 80386\n");
	else if (EM_SPARC == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
		printf("Sparc\n");
	else if (EM_NONE == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
		printf("An unknown machine\n");
	else
		printf("Unknown Type: %x\n",
		(unsigned char) ((Elf32_Ehdr *)ls)->e_machine);
	PRINT_LABEL("Version:");
	if (EV_CURRENT == (unsigned char) ((Elf32_Ehdr *)ls)->e_version)
		printf("0x1\n");
	else
		printf("0x0\n");
}

/**
 * entryp32 - Print the elf header entry point
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void entryp32(char *ls)
{
	Elf32_Addr thiself;

	PRINT_LABEL("Entry point address:");
	printf("0x%x\n", ((Elf32_Ehdr *)ls)->e_entry);
	thiself = ((Elf32_Ehdr *)ls)->e_entry;
	SWAP(thiself);
}

