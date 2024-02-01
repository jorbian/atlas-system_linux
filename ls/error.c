#include "hls.h"

/**
 * error_dump - handles errors
 * @exec: name of program executable
 * @filename: name of file that caused error
 * @code: represents error code
*/

void error_dump(c_dt *cmd)
{
	if (cmd->error_info == 2)
		fprintf(
			stderr,
			"%s: cannot access %s: No such file or directory\n",
			cmd->app_name, cmd->foldername
		);
	else if (cmd->error_info == 13)
		fprintf(
			stderr,
			"%s: cannot open directory %s: Permission denied\n",
			cmd->app_name, cmd->foldername
		);
	else
		perror("eRrOr");

	free_cdt(
		&(cmd->dir_list),
		&(cmd->file_list)
	);

	exit(1);
}
