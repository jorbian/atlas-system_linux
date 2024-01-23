#ifndef HLS_H
#define HLS_H

#include <stdint.h>

#define SHIFT_RIGHT 4
#define DEFAULT_BUFF_SIZE 127
#define MAX_PATH_LEN 1025
#define DEFAULT_OPTION "."
#define TEST_FOLER_NAME "/home/boller/code/holbertonschool-system_linux"
#define FLAG_GLYPHS "Aa1l"

/**
 * enum error_type_t - index of the error type on the other arrays
 * @#include "error_type.def";#undef ERROR_TYPE: asdf
*/
enum error_type_t
{
	#define ERROR_TYPE(x, y) x,
		#include "error_type.def"
	#undef ERROR_TYPE
	NUM_ERROR_TYPES
};

/**
 * struct ls_s - context struct for execution of hls
 * @folder: the name of the folder (or other item) to be listed
 * @child_item_names: names of items the folder contains in directory
 * @num_children: number of child items in folder.
 * 
*/
typedef struct ls_s
{
	char app_name[DEFAULT_BUFF_SIZE];
	char folder[MAX_PATH_LEN];
	char **child_item_names;
	uint32_t num_children;
	uint32_t flag_token;
	uint32_t non_directory;
	uint32_t error_info;
} ls_t;

#define SET_BIT(bit, value) ((1 << bit) | value)

void initalize_context(ls_t *context, int argc, char **argv);
void throw_error(ls_t *context);

#endif
