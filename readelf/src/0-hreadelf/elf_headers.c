#include "task0.h"

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
