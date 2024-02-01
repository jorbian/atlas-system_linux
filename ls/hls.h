#ifndef _HLS_H_
#define _HLS_H_

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

/**
 * struct list_entry - list of directories related to command data
 * @name: name of directory
 * @next: next directory entry in list
 * @prev: previous directory entry in list
*/
typedef struct list_entry
{
	char *name;
	struct list_entry *next;
	struct list_entry *prev;
} entry_t;

/**
 * struct command_data - structure to retain data from command input
 * @arg_c: count of arguments minus the first argument (executable name)
 * @dir_count: count of directories of which to find contents
 * @dir_list: list of directories of which to find contents
 * @file_count: count of input files to be displayed
 * @entry_tist: list of file elements in input
 * @flags: hex value corresponding to bits set based on flags requested
*/
typedef struct command_data
{
	char app_name[16];
	char foldername[1025];
	uint32_t flags: 16;
	uint32_t error_info: 16;
	uint32_t file_count: 16;
	uint32_t dir_count: 16;
	entry_t *dir_list;
	entry_t *file_list;
} c_dt;

void initalize_context(c_dt *cmd, char **argv);
int perform_listing(c_dt *cmd);
void print_manager(c_dt *cmd);
int add_to_entry_list(char *filename, entry_t **list);
void create_entry_list(c_dt *cmd);
void free_cdt(entry_t **d_list, entry_t **f_list);
void error_dump(c_dt *cmd);

char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

#endif
