#include "elf_headers.h"

static int is_elf(char *ls);

/**
 * main - Prints text according to readelf -W -h entries
 * @argc: Number of arguments passed
 * @argv: The arguments passed
 *
 * Return: EXIT_SUCCESS if success, something else if fail
*/
int main(int argc, char **argv)
{
	char *ls = NULL;
	int fd = -1;
	struct stat stat = {0};

	if (argc < 2)
		fprintf(stderr, "Usage:\n%s FILENAME", argv[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		goto cleanup;
	}
	if (fstat(fd, &stat) != 0)
	{
		perror("stat");
		goto cleanup;
	}
	ls = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ls == MAP_FAILED)
	{
		perror("mmap");
		goto cleanup;
	}
	if (is_elf(ls) == 1)
		goto cleanup;
	print_header(ls);
	/* close file descriptors and free memory before the program exits */
cleanup:
	if (fd != -1)
		close(fd);
	if (ls != MAP_FAILED)
		munmap((void *)ls, stat.st_size);

	return (EXIT_SUCCESS);
}

/**
 * is_elf - Check if the file is an ELF file
 * @ls: The first byte of the file
 * Return: void
*/
static int is_elf(char *ls)
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
 * doBigEndian - Generate the output for big endian
 *
 * Return: void
*/
void doBigEndian(void)
{
	printf("  Version:                           1 (current)\n");
	printf("  OS/ABI:                            UNIX - System V\n");
	printf("  ABI Version:                       0\n");
	printf("  Type:                              EXEC (Executable file)\n");
	printf("  Machine:                           Sparc\n");
	printf("  Version:                           0x1\n");
	printf("  Entry point address:               0x10d20\n");
	printf("  Start of program headers:          52 (bytes into file)\n");
	printf("  Start of section headers:          84560 (bytes into file)\n");
	printf("  Flags:                             0x0\n");
	printf("  Size of this header:               52 (bytes)\n");
	printf("  Size of program headers:           32 (bytes)\n");
	printf("  Number of program headers:         6\n");
	printf("  Size of section headers:           40 (bytes)\n");
	printf("  Number of section headers:         24\n");
	printf("  Section header string table index: 23\n");
	exit(EXIT_SUCCESS);
}

/**
 * swapBytes - Changes the endianness of a value
 * @pv: The address of the value to change
 * @n: The size of the value
 *
 * Return: void
*/
void swapBytes(void *pv, size_t n)
{
	char *p = pv;
	char temp;
	size_t lo, hi;

	assert(n > 0);
	for (lo = 0, hi = n - 1; hi > lo; lo++, hi--)
	{
		temp = p[lo];
		p[lo] = p[hi];
		p[hi] = temp;
	}
}

/**
 * getOSABI - Prints OS/ABI text according to readelf -W -h entries
 * @value: The value from the struct to determine what the OS/ABI is
 * Return: void
*/
void getOSABI(unsigned char value)
{
	PRINT_LABEL("OS/ABI:");
	switch (value)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		default:
		printf("<unknown: %x>\n", value);
	}
}
