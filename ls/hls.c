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

	(void)argc;

	initalize_context(&cmd, argv);

	create_entry_list(&cmd);
	if (cmd.error_info)
		error_dump(&cmd);

	print_manager(&cmd);

	free_cdt(
		&(cmd.dir_list),
		&(cmd.file_list)
	);
	return (0);
}
