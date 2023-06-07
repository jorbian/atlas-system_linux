#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stdio.h>
#include <stdlib.h>

#define FIRST_CHAR(str) ((int)(str[0])) /* decimal value of first char */
#define NTH_CHAR(str, idx) ((int)(str[idx])) /* same but anywhere else */
#define TOLOWER(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)
#define TOUPPER(c) ((c >= 'a' && c <= 'z') ? (c + ('A' - 'a')) : c)

/* VARIOUS REINVENTIONS OF THE WHEEL */
char *_strdup(const char *old_string);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
void *_memcpy(void* destination, const void* source, size_t num);
void quick_sort(void *base, size_t len, size_t element_size,
	int (*comp)(const void *, const void *));
int string_comp(const void *a, const void *b);

/* LIFE AND DEATH OF STRING ARRAYS */
char **new_string_array(size_t length);
void list_string_array(char **array);
char **search_array(char **array, size_t length, int (*terms)(const char*));
void free_string_array(char **array);

#endif