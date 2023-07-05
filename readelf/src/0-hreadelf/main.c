#include "task0.h"

/**
 * main - Prints text according to readelf -W -h entries
 * @argc: Number of arguments passed
 * @argv: The arguments passed
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
	print_elf_header(ls);
	/* close file descriptors and free memory before the program exits */
cleanup:
	if (fd != -1)
		close(fd);
	if (ls != MAP_FAILED)
		munmap((void *)ls, stat.st_size);

	return (EXIT_SUCCESS);
}

/**
 * print_elf_header - Print the elf header
 * @ls: The first byte of the file
 * Return: void
*/

void print_elf_header(char *ls)
{
	print_magic_bytes(ls);
	print_elf_class(ls);
	print_endianness(ls);
	getOSABI((unsigned char)ls[EI_OSABI]);
	labelPrint("ABI Version:");
	printf("%u\n", (unsigned char)ls[EI_ABIVERSION]);

	if ((unsigned char)ls[EI_CLASS] == ELFCLASS64)
		print_elf_64bit(ls);
	else if ((unsigned char)ls[EI_CLASS] == ELFCLASS32)
		print_elf_32bit(ls);

}
