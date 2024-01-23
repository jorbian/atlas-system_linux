#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdint.h>

#include "./inc/hls.h"
#include "./inc/ZZstring.h"

/**
 * allocate_buffer - allocate a storage buffer for child item names
 * @size: the number of char pointers that need to be allocated for strings
 *
 * Return: A pointer to the newly allocated double pointer.
*/
static char **allocate_buffer(uint32_t size)
{
	uint32_t i;

	char **new_buffer;

	new_buffer = (
		(char **)malloc(size * sizeof(char *))
	);

	if (!new_buffer)
		return (NULL);

	if (new_buffer)
		for (i = 0; i < size; i++)
			new_buffer[i] = (char *)malloc(MAX_PATH_LEN);

	return (new_buffer);
}

/**
 * count_items - count the number of items in folder
 * @folder: the name of the folder being counted
 *
 * Return: How many items were in the folder.
*/
static uint64_t count_items(const char *folder)
{
	DIR *dir;
	struct dirent *ent;

	int count = 0;

	dir = opendir(folder);

	if (dir != NULL)
		while ((ent = readdir(dir)) != NULL)
			count++;

	closedir(dir);

	return (count);
}

/**
 * fill_name_buffer - traverse the given folder and list item names
 * @context: pointer to the ls_t context struct
*/
static void fill_name_buffer(ls_t *context)
{
	DIR *dir;

	struct dirent *ent;

	int index = 0;

	dir = opendir(context->folder);

	while ((ent = readdir(dir)) != NULL)
	{
		ZZstrncpy(
			context->child_item_names[index],
			ent->d_name,
			MAX_PATH_LEN
		);
		index++;
	}
	closedir(dir);
}

/**
 * get_child_items - initally generate list of folder's child items
 * @context: pointer to the ls_t context struct
 *
*/
void get_child_items(ls_t *context)
{
	uint32_t *needed_buffer = &(context->num_children);
	uint32_t *error = &(context->error_info);

	*needed_buffer = count_items(context->folder);

	context->child_item_names = allocate_buffer(*needed_buffer);

	if (!context->child_item_names)
	{
		*error = SET_BIT(MALLOC_FAIL, *error);
		throw_error(context);
	}

	fill_name_buffer(context);
}
