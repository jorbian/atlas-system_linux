#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdint.h>

#include "hls.h"

/**
 * allocate_buffer - allocate a storage buffer for child item names
 * @size: the number of char pointers that need to be allocated for strings
 *
 * Return: A pointer to the newly allocated double pointer.
*/
static char **allocate_buffer(uint64_t size)
{
	uint64_t i;

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
 * @buff: the buffer to stor the names as strings
 * @size: how big the buffer is supposed to be
*/
static void fill_name_buffer(char **buff, uint64_t size)
{
	DIR *dir;
	struct dirent *ent;

	int index = 0;

	dir = opendir(FOLDER_NAME);

	while ((ent = readdir(dir)) != NULL)
	{
		snprintf(buff[index], MAX_PATH_LEN, "%s", ent->d_name);
		index++;
	}
	closedir(dir);
}

