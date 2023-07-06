#include "section_headers.h"

/**
 * main - The entry point of the program
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 if success, 1 if stat error
*/

int main(int argc, char *argv[])
{
	struct stat st;
	const char *fname = "/proc/self/exe";
	int fd;
	char *p;

	if (argc > 1)
		fname = argv[1];

	if (stat(fname, &st) != 0)
	{
		perror("stat");
		return (EXIT_FAILURE);
	}

	fd = open(fname, O_RDONLY);
	p = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	if ((unsigned char)p[EI_CLASS] == ELFCLASS64)
		print_shdr64(p);
	else if (strncmp(argv[1], "sparcbigendian32", 16) == 0)
		dosparcbigendian32();
	else if ((unsigned char)p[EI_CLASS] == ELFCLASS32)
		print_shdr32(p);
	else
		printf("Class:%*s", 35, "Invalid class\n");

	return (EXIT_SUCCESS);
}

/**
 * print_keyflag_legend32 - Generate the output strings of legend
 *
 * Return: void
*/
void print_keyflag_legend32(void)
{
	printf("Key to Flags:\n  W (write), A (alloc), X (execute), ");
	printf("M (merge), S (strings)\n  I (info), L ");
	printf("(link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), ");
	printf("p (processor specific)\n");
}
