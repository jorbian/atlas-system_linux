#include "task0.h"

/**
 * print_entryp32 - Print the elf header entry point
 * @ls: The first byte of the file
 * Return: void
*/

void print_entryp32(char *ls)
{
	Elf32_Addr thiself;

	labelPrint("Entry point address:");
	printf("0x%x\n", ((Elf32_Ehdr *)ls)->e_entry);
	thiself = ((Elf32_Ehdr *)ls)->e_entry;
	SWAP(thiself);
}
/**
 * print_elf_32bit - Print the elf header info
 * @ls: The first byte of the file
 * Return: void
*/
void print_elf_32bit(char *ls)
{
	print_type32(ls);
	print_machine32(ls);
	print_entryp32(ls);
	labelPrint("Start of program headers:");
	printf("%u (bytes into file)\n", ((Elf32_Ehdr *)ls)->e_phoff);
	labelPrint("Start of section headers:");
	printf("%u (bytes into file)\n", ((Elf32_Ehdr *)ls)->e_shoff);
	labelPrint("Flags:");
	printf("0x");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_flags);
	labelPrint("Size of this header:");
	printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_ehsize);
	labelPrint("Size of program headers:");
	printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_phentsize);
	labelPrint("Number of program headers:");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_phnum);
	labelPrint("Size of section headers:");
	printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_shentsize);
	labelPrint("Number of section headers:");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_shnum);
	labelPrint("Section header string table index:");
	printf("%u\n", ((Elf32_Ehdr *)ls)->e_shstrndx);
}

/**
 * print_type32 - Print the elf type
 * @ls: The first byte of the file
 *
 * Return: void
*/
void print_type32(char *ls)
{
	labelPrint("Type:");
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
 * print_machine32- Print the elf machine info
 * @ls: The first byte of the file
 *
 * Return: void
*/
void print_machine32(char *ls)
{
	labelPrint("Machine:");
	if (EM_386 == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
		printf("Intel 80386\n");
	else if (EM_SPARC == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
		printf("Sparc\n");
	else if (EM_NONE == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
		printf("An unknown machine\n");
	else
		printf("Unknown Type: %x\n",
		(unsigned char) ((Elf32_Ehdr *)ls)->e_machine);
	labelPrint("Version:");
	if (EV_CURRENT == (unsigned char) ((Elf32_Ehdr *)ls)->e_version)
		printf("0x1\n");
	else
		printf("0x0\n");
}
