#include "task0.h"

static void type64(char *ls);
static void machine64(char *ls);

/**
 * print_elf_64bit - Print the elf header info
 * @ls: The first byte of the file
 *
 * Return: void
*/
void print_64bit(char *ls)
{
	type64(ls);
	machine64(ls);
	PRINT_LABEL("Entry point address:");
	printf("0x%lx\n", ((Elf64_Ehdr *)ls)->e_entry);
	PRINT_LABEL("Start of program headers:");
	printf("%lu (bytes into file)\n", ((Elf64_Ehdr *)ls)->e_phoff);
	PRINT_LABEL("Start of section headers:");
	printf("%lu (bytes into file)\n", ((Elf64_Ehdr *)ls)->e_shoff);
	PRINT_LABEL("Flags:");
	printf("0x");
	printf("%u\n", ((Elf64_Ehdr *)ls)->e_flags);
	PRINT_LABEL("Size of this header:");
	printf("%u (bytes)\n", ((Elf64_Ehdr *)ls)->e_ehsize);
	PRINT_LABEL("Size of program headers:");
	printf("%u (bytes)\n", ((Elf64_Ehdr *)ls)->e_phentsize);
	PRINT_LABEL("Number of program headers:");
	printf("%u\n", ((Elf64_Ehdr *)ls)->e_phnum);
	PRINT_LABEL("Size of section headers:");
	printf("%u (bytes)\n", ((Elf64_Ehdr *)ls)->e_shentsize);
	PRINT_LABEL("Number of section headers:");
	printf("%u\n", ((Elf64_Ehdr *)ls)->e_shnum);
	PRINT_LABEL("Section header string table index:");
	printf("%u\n", ((Elf64_Ehdr *)ls)->e_shstrndx);
}


/**
 * type64 - Print the elf header type
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void type64(char *ls)
{
	PRINT_LABEL("Type:");
	if (ET_CORE == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
		printf("CORE (Core file)\n");
	else if (ET_EXEC == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
		printf("EXEC (Executable file)\n");
	else if (ET_REL == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
		printf("REL (Relocatable file)\n");
	else if (ET_DYN == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
		printf("DYN (Shared object file)\n");
	else if (ET_NONE == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
		printf("Unknown type\n");
	else
		printf("Something weird\n");
}

/**
 * machine64 - Print the machine type
 * @ls: The first byte of the file
 *
 * Return: void
*/
static void machine64(char *ls)
{
	PRINT_LABEL("Machine:");
	if (EM_X86_64 == (unsigned char) ((Elf64_Ehdr *)ls)->e_machine)
		printf("Advanced Micro Devices X86-64\n");
	else if (EM_SPARC == (unsigned char) ((Elf64_Ehdr *)ls)->e_machine)
		printf("Sparc\n");
	else
		printf("Unknown Type\n");
	PRINT_LABEL("Version:");
	if (EV_CURRENT == (unsigned char) ((Elf64_Ehdr *)ls)->e_version)
		printf("0x1\n");
	else
		printf("0x0\n");
}
