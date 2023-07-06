#include "program_headers.h"

/**
 * phflag_to_str32 - Generate the output string of phflags
 * @phflag: the program header flag from phdr, 32 bits
 * @phtype: the output string address
 * 
 * Return: The string of the phflag
*/
char *phflag_to_str32(Elf32_Word phflag, char *phtype)
{
	memcpy(phtype, "   ", 4);
	if (phflag & PF_R)
		phtype[0] = 'R';
	if (phflag & PF_W)
		phtype[1] = 'W';
	if (phflag & PF_X)
		phtype[2] = 'E';
	return (phtype);
}

/**
 * print_segments32 - Generate the output from segments, 32 bit
 * @p: The first byte of the elf file
 * 
 * Return: void
*/
void print_segments32(char *p)
{
	Elf32_Ehdr *ehdr = (Elf32_Ehdr *)p;
	Elf32_Phdr *phdr = (Elf32_Phdr *)(p + ehdr->e_phoff);
	Elf32_Shdr *shdr = (Elf32_Shdr *)(p + ehdr->e_shoff);
	int phnum = ehdr->e_phnum;
	int shnum = ehdr->e_shnum;
	Elf32_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = p + sh_strtab->sh_offset;
	int i = 0, j = 0;
	Elf32_Off pl, ph, sl, sh;

	printf("\n Section to Segment mapping:\n  Segment Sections...\n");
	(void) phdr;
	(void) sh_strtab_p;

	for (i = 0; i < phnum; ++i)
	{
		pl = phdr[i].p_offset;
		ph = phdr[i].p_offset + phdr[i].p_memsz;
		printf("   %02d     ", i);
		for (j = 0; j < shnum; ++j)
		{
			if (shdr[j].sh_addr == 0 || shdr[j].sh_size == 0)
				continue;
			sl = shdr[j].sh_offset;
			sh = shdr[j].sh_offset + shdr[j].sh_size;
			if (pl <= sl && sh <= ph)
				printf("%s ", sh_strtab_p + shdr[j].sh_name);
		}
		printf("\n");
	}
}

/**
 * print_phdr32 - Generate the output from program headers, 32 bit
 * @p: The first byte of the elf file
 * 
 * Return: 0 if success, 1 if no headers
*/
int print_phdr32(char *p)
{
	Elf32_Ehdr *ehdr = (Elf32_Ehdr *)p;
	Elf32_Phdr *phdr = (Elf32_Phdr *)(p + ehdr->e_phoff);
	Elf32_Off phoff = ehdr->e_phoff;
	int phnum = ehdr->e_phnum;
	int i = 0;
	char phtype[4] = "   \0";

	if (phnum == 0)
	{
		printf("\nThere are no program headers in this file.\n");
		return (EXIT_FAILURE);
	}

	printf("\nElf file type is %s\n", etype_to_str32(ehdr->e_type));
	printf("Entry point 0x%x\nThere are ", ehdr->e_entry);
	printf("%d program headers, starting at offset %d", phnum, phoff);
	printf("\n\nProgram Headers:\n  Type           Offset   VirtAddr");
	printf("   PhysAddr   FileSiz MemSiz  Flg Align\n");
	for (i = 0; i < phnum; ++i)
	{
		printf("  %-13s  ", phtype_to_str32(phdr[i].p_type));
		printf("0x%06x ", phdr[i].p_offset);
		printf("0x%08x ", phdr[i].p_vaddr);
		printf("0x%08x ", phdr[i].p_paddr);
		printf("0x%05x ", phdr[i].p_filesz);
		printf("0x%05x ", phdr[i].p_memsz);
		printf("%s ", phflag_to_str32(phdr[i].p_flags, phtype));
		if (phdr[i].p_align == 0)
			printf("0");
		else
			printf("0x%x", phdr[i].p_align);
		printf("\n");
		if (phdr[i].p_type == PT_INTERP)
		{
			printf("      [Requesting program interpreter: ");
			printf("%s]\n", (char *) (phdr[i].p_offset + p));
		}
	}
	print_segments32(p);
	return (EXIT_SUCCESS);
}

/**
 * etype_to_str32 - Find the string output for a given elf type, 32 bit
 * @etype: the elf type from ehdr
 * 
 * Return: The string of the etype
*/
char *etype_to_str32(Elf32_Half etype)
{
	if (etype == ET_CORE)
		return ("CORE (Core file)");
	else if (etype == ET_EXEC)
		return ("EXEC (Executable file)");
	else if (etype == ET_REL)
		return ("REL (Relocatable file)");
	else if (etype == ET_DYN)
		return ("DYN (Shared object file)");
	else if (etype == ET_NONE)
		return ("Unknown type");
	else
		return ("Something weird");
}

/**
 * phtype_to_str32 - Find the string output for a given program header type
 * @phtype: the program header type from phdr, 32 bits
 * 
 * Return: The string of the phtype
*/
char *phtype_to_str32(Elf32_Word phtype)
{
	switch (phtype)
	{
	case PT_PHDR:
		return ("PHDR");
	case PT_LOAD:
		return ("LOAD");
	case PT_DYNAMIC:
		return ("DYNAMIC");
	case PT_NOTE:
		return ("NOTE");
	case PT_GNU_EH_FRAME:
		return ("GNU_EH_FRAME");
	case PT_GNU_STACK:
		return ("GNU_STACK");
	case PT_GNU_RELRO:
		return ("GNU_RELRO");
	case PT_INTERP:
		return ("INTERP");
	case 0x6464e550:
		return ("LOOS+464e550");
	default:
		break;
	}
	return (NULL);
}
