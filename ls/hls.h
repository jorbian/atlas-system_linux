#ifndef HLS_H
#define HLS_H

#include <stdint.h>

#define MAX_PATH_LEN 1025
#define FOLDER_NAME "/home/boller/code/holbertonschool-system_linux"

/**
 * struct ls_s - context struct for execution of hls
 * @folder: the name of the folder (or other item) to be listed
 * @child_item_names: names of items the folder contains in directory
 * @num_children: number of child items in folder.
 * 
*/
typedef struct ls_s
{
	char folder[MAX_PATH_LEN];
	char **child_item_names;
	uint32_t num_children;
	uint32_t non_directory;
	uint32_t error_info;
} ls_t;

const char flag_glyphs[] = {
	#define GLYPHS(a, b) b,
		#include "flags.def"
	#undef GLYPHS
};

#define SET_FLAG(bit, token) ((1 << bit) | token)

#endif
