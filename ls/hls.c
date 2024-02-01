#include <stdint.h>

#include "hls.h"

/**
 * main - program entry
 * @argc: argument count to program
 * @argv: vector of input arguments
 * Return: 0 upon success
*/
int main(int argc, char **argv)
{
	c_dt cmd;

	if (argc < 2)	
		exit(1);

	initalize_context(&cmd, argv);
	create_entry_list(&cmd);
	print_manager(&cmd);
	free_cdt(&(cmd.dir_list), &(cmd.file_list));
	return (0);
}
