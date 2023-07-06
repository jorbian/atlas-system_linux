#include "section_headers.h"

/**
 * print_shdr64 - Generate the output of the section headers
 * @p: The first byte of the elf file
 *
 * Return: always 0
*/
int print_shdr64(char *p)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr *)p;
	Elf64_Shdr *shdr = (Elf64_Shdr *)(p + ehdr->e_shoff);
	int shnum = ehdr->e_shnum;
	Elf64_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = p + sh_strtab->sh_offset;
	Elf64_Word shtype;
	int i = 0;
	char retval[4] = "\0\0\0\0";

	printf("There are %d section headers, starting at offset %p:\n",
		shnum, (void *) ehdr->e_shoff);
	printf("\nSection Headers:\n");
	printf("  [Nr] Name              Type            Address          ");
	printf("Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < shnum; ++i)
	{
		memcpy(retval, "\0\0\0\0", 4);
		shtype = shdr[i].sh_type;
		printf("  [%2d] %-17s ", i,
		sh_strtab_p + shdr[i].sh_name);

		printf("%-16s", sht_str64(shtype));
		printf("%016lx ", shdr[i].sh_addr);
		printf("%06lx ", shdr[i].sh_offset);
		printf("%06lx ", shdr[i].sh_size);
		printf("%02lx ", shdr[i].sh_entsize);
		printf("%3s ", flg_to_str64(retval, shdr[i].sh_flags));
		printf("%2d ", shdr[i].sh_link);
		printf("%3d ", shdr[i].sh_info);
		printf("%2ld\n", shdr[i].sh_addralign);
	}
	print_keyflag_legend32();
	return (EXIT_SUCCESS);
}

/**
 * sht_str64 - Find the string output for a given section header type
 * @shtype: the program header type from shdr, 64 bits
 * Return: The string of the shtype
*/

char *sht_str64(Elf64_Word shtype)
{
	switch (shtype)
	{
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_DYNSYM:
		return ("DYNSYM");
	case SHT_NOTE:
		return ("NOTE");
	case SHT_GNU_HASH:
		return ("GNU_HASH");
	case SHT_STRTAB:
		return ("STRTAB");
	case SHT_GNU_versym:
		return ("VERSYM");
	case SHT_GNU_verneed:
		return ("VERNEED");
	case SHT_RELA:
		return ("RELA");
	case SHT_INIT_ARRAY:
		return ("INIT_ARRAY");
	case SHT_FINI_ARRAY:
		return ("FINI_ARRAY");
	case SHT_DYNAMIC:
		return ("DYNAMIC");
	case SHT_NOBITS:
		return ("NOBITS");
	case SHT_SYMTAB:
		return ("SYMTAB");
	case SHT_REL:
		return ("REL");
	case SHT_HASH:
		return ("HASH");
	case SHT_NULL:
		return ("NULL");
	default:
		break;
	}

	return (NULL);
}

/**
 * flg_to_str64 - Generate the output string of shflags
 * @flags: the program header flag from shdr, 64 bits
 * @retval: the output string address
 *
 * Return: The string of the shflag
*/
char *flg_to_str64(char *retval, Elf64_Xword flags)
{
	short i = 0;

	if (SHF_WRITE & flags)
	{
		retval[i] = 'W';
		i++;
	}
	if (SHF_ALLOC & flags)
	{
		retval[i] = 'A';
		i++;
	}
	if (SHF_EXECINSTR & flags)
	{
		retval[i] = 'X';
		i++;
	}
	if (SHF_MERGE & flags)
	{
		retval[i] = 'M';
		i++;
	}
	if (SHF_STRINGS & flags)
	{
		retval[i] = 'S';
		i++;
	}
	if (SHF_INFO_LINK & flags)
	{
		retval[i] = 'I';
		i++;
	}
	if (SHF_EXCLUDE & flags)
	{
		retval[i] = 'E';
		i++;
	}
	return (retval);
}
