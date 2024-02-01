#include "hls.h"

static char flag_glyphs[] = {
	#define FLAG(a, b) b,
		#include "flag.def"
	#undef FLAG
};

/**
 * index_of - finds the first occurance of a character in a string
 * @p: string to search for the character in
 * @ch: the character being searched for in the string
 *
 * Return: Index of the first occurence of the character
*/
static ssize_t index_of(char *p, int ch)
{
	char c, *q;

	c = ch;
	q = p;

	for (;; ++q)
	{
		if (*q == c)
			return (q - p);
		if (*q == '\0')
			return (-1);
	}
}

/**
 * flag_setter - modfies the flag token based on glyph
 * @flag: the glyph found back in parse args
 * @flag_token: pointer to the flag token on context struct
 *
 * Return: Whether or not there was some kind of problem.
*/
static int flag_setter(char flag, uint32_t *flag_token)
{
	ssize_t flag_index = 0;

	if (!flag)
		return (-1);

	flag_index = index_of(flag_glyphs, flag);
	if (flag_index != -1)
		*flag_token |= (1 << flag_index);

	return (0);
}

/**
 * parse_args - process arguments by flags &/or directory names
 * @argv: argument vector, passed from main for processing
 * @cmd: command data struct
 *
 * Return: -1 upon NULL input or logistics failure, 0 otherwise
*/
static int parse_args(c_dt *cmd, char **argv)
{
	char **i, *j;

	uint32_t flag_token = 0;

	if (!argv || !cmd)
		return (-1);

	for (i = argv; *i; i++)
	{
		j = i[0];

		if (*j == '-')
		{
			flag_setter(j[1], &flag_token);
			continue;
		}
		_strcpy(cmd->foldername, j);
	}
	cmd->flags = flag_token;

	return (0);
}

/**
 * initalize_context - intitalize the c_dt context struct
 * @cmd: pointer to the empty struct back in main
 * @argv: program arguments as passed up from main
 *
*/
void initalize_context(c_dt *cmd, char **argv)
{
	cmd->dir_count = 0,
	cmd->dir_list = NULL;
	cmd->file_count = 0,
	cmd->file_list = NULL,
	cmd->flags = 0x00;

	parse_args(cmd, argv);
}

/**
 * perform_listing - fill
 * @argument: argv element
 * @cmd: command data struct
 *
 * Return: -1 upon lstat failure, 0 otherwise
*/
int create_entry_list(c_dt *cmd)
{
	struct stat file_stat;

	if (lstat(cmd->foldername, &file_stat) != -1)
	{
		if (S_ISDIR(file_stat.st_mode))
			add_to_entry_list(cmd->foldername, &cmd->dir_list), cmd->dir_count++;
		else
			add_to_entry_list(cmd->foldername, &cmd->file_list), cmd->file_count++;
	}
	else
		return (-1);

	return (0);
}
