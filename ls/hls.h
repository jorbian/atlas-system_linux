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

#define MAX_PATH_LENGTH 1024

size_t ping_dir_len(const char *path);
char **just_get_names(const char *path, size_t num_entries);
void simple_listing(char const *path);
int contains_flag(const char *arg_value);
int is_name_of_hidden_item(const char *arg_value);

#endif