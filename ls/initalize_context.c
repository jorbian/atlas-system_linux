#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "./inc/hls.h"

/**
 * interpret_flags - interpret generated flag string
 * @context: pointer to the ls_t context struct
 * @flags: string containing potential flags found in args
 *
*/
static void interpret_flags(ls_t *context, char *flags)
{
	char index, *glyphs = FLAG_GLYPHS;

	uint32_t *token = &(context->flag_token);
	uint32_t *error = &(context->error_info);

	if (flags != NULL)
		while (*flags)
		{
			index = (char)index_of(glyphs, *flags);
			if (index != -1)
				*token = SET_BIT(index, *token);
			else
			{
				*error = SET_BIT(1, *error);
				context->folder[0] = *flags;
				context->folder[1] = '\0';
				break;
			}
			*(flags++);
		}
}

/**
 * find_flags - does a bunch of pointer chenanigans to sort params
 * @context: pointer to the ls_t context struct
 * @flag_buff: buffer to store whatever flag values end up found
 * @params: double pointer to whatever &argv[1] was
 *
*/
static void find_flags(ls_t *context, char *flag_buff, char **params)
{
	char **i, *j;

	for (i = params; *i; i++)
	{
		j = i[0];

		if (*j == '-')
		{
			*flag_buff = *(j + 1);
			flag_buff++;
			continue;
		}
		ZZstrncpy(context->folder, *i, MAX_PATH_LEN);
	}
	*flag_buff = '\0';
}

/**
 * test_folder_path - tests the folder path given in argv
 * @context: pointer to the ls_t context struct
 *
*/
static void test_folder_path(ls_t *context)
{
	struct stat statbuf;

	if (stat(context->folder, &statbuf) != 0)
		context->error_info = (
			SET_BIT(0, context->error_info)
		);

	if (!context->error_info)
	{
		context->non_directory = !S_ISDIR(statbuf.st_mode);
	}
}

/**
 * initalize_context - routines to initalize context struct based on argv
 * @context: pointer to the ls_t context struct
 * @argc: number of program arguments passed up from main
 * @argv: program arguments as passed up from main
 *
*/
void initalize_context(ls_t *context, int argc, char **argv)
{
	char flag_buff[255];

	context->flag_token = 0;
	context->error_info = 0;
	context->non_directory = 0;

	if (argc > 1)
	{
		find_flags(context, flag_buff, (char **)&argv[1]);
		interpret_flags(context, flag_buff);
	}
	else
		ZZstrncpy(context->folder, DEFAULT_OPTION, MAX_PATH_LEN);

}
