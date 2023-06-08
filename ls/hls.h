#ifndef HLS_H
#define HLS_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

#include "my_strings.h"

/* MACROS AND FUNCTION LIKE MACROS */

#define IS_NOT_HIDDEN(c) (NTH_CHAR(c, 0) != 46)
#define HAS_FLAG(c) (FIRST_CHAR(c) == 45)
#define NO_FLAG(c) (FIRST_CHAR(c) != 45)
#define SUPPORTED_FLAGS "laA1"
#define NUM_SUPPORTED 4
#define DEFAULT_BUFFER 255

/* TOP LEVEL DATA STRUCTURES */

/**
 * struct DirectoryLister - doubly linked list representation of a stack (or queue)
 * @items_to_list: names of the items to be listed (or not)
 * @flags: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct DirectoryLister
{
    size_t num_of_items;
    char **items_to_list;
    char current_item[DEFAULT_BUFFER];
    char error_message[DEFAULT_BUFFER];
    char flag_token;
} dir_ls;

size_t ping_dir_len(const char *path);
char **just_get_names(const char *path, size_t num_entries);
void simple_listing(char const *path);
void _simple_listing(char const *path);
int no_flag(const char *arg_value);
int has_flag(const char *arg_value);
int is_name_of_hidden_item(const char *arg_value);

dir_ls *create_dir_lister(int argc, char **argv);
void activate_lister(dir_ls *ls);
void deinitilize_dir_lister(dir_ls *ls);

#endif
