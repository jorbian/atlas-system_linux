#include "hls.h"

/**
 * main - the entry point for the program
 * @argc: number of arguments
 * @argv: paramters fed into program
 *
 * Return: Just zero.
*/
int main(int argc, char **argv)
{
	dir_ls *ls = create_dir_lister(argc, argv);

	if (ls)
	{
		activate_lister(ls);
		deinitilize_dir_lister(ls);
	}

	return (0);
}
