#include "hls.h"

/**
 * ping_dir_len - ping the length of a directory
 * @path: path to the directory
 *
 * Return: Number of entries we have to allocate memory for
*/
size_t ping_dir_len(const char *path)
{
	DIR *dir;
	struct dirent *entry;

	size_t num_entries = 0;

	dir = opendir(path);

	while ((entry = readdir(dir)) != NULL)
		num_entries++;

	closedir(dir);

	return (num_entries);
}

/**
 * just_get_names - cares only about the names of the items
 * @path: path to the directory
 * @num_entries: pre-pinged size of directory
 *
 * Return: Double pointer to the array just retrieved.
*/
char **just_get_names(const char *path, size_t num_entries)
{
	int i = 0;
	DIR *dir;
	struct dirent *entry;

	char **entry_names;

	entry_names = new_string_array(num_entries);
	if (entry_names == NULL)
		return (NULL);

	dir = opendir(path);

	while ((entry = readdir(dir)) != NULL)
		entry_names[i++] = _strdup(entry->d_name);

	closedir(dir);

	quick_sort(entry_names, num_entries, sizeof(char *), string_comp);

	return (entry_names);
}

/**
 * is_name_of_hidden_item - used to find the names of hidden items
 * @arg_value: string cointing argv value
 *
 * Return: '1' for True, the value is 45, '0' for False.
*/
int is_name_of_hidden_item(const char *arg_value)
{
	return (
		(NTH_CHAR(arg_value, 0) == 46) ||
		(NTH_CHAR(arg_value, 1) == 46)
	);
}

/**
 * no_flag - whether the first char is anything but 45
 * @arg_value: individual arg passed to program
 * 
 * Return: Whether the dec value of its first char isn't 45
*/
int no_flag(const char *arg_value)
{
	return(FIRST_CHAR(arg_value) != 45);
}

/**
 * simple_listing - just enough to get tasks one and two done
 * @path: path to some directory
 *
*/
void simple_listing(char const *path)
{
	char **item_names = NULL;

	size_t length = ping_dir_len(path);
	size_t i = 0;

	item_names = just_get_names(path, length);
	if (item_names == NULL)
		return;

	for (i = 0; i < length; i++)
	{
		if (IS_NOT_HIDDEN(item_names[i]))
			printf("%s  ", item_names[i]);
	}
	printf("\n");

	free_string_array(item_names);
}
