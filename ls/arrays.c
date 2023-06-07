#include "my_strings.h"

/**
 * new_string_array - allocates a place in memory for array of x length
 * @length: however long the array needs to be
 * 
 * Return: Double pointer to first index
*/
char **new_string_array(size_t length)
{
    char **new_array;

    new_array = malloc((length + 1) * sizeof(char *));
    if (new_array == NULL)
        return (NULL);

    new_array[length] = NULL;

    return (new_array);
}

/**
 * free_string_array - deallocates a string array from memory
 * @array: the array that's no longer needed
*/
void free_string_array(char **array)
{
    size_t i = 0;

    if (array == NULL)
        return;

    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

/**
 * list_string_array - deallocates a string array from memory
 * @array: array to be looked at
*/
void list_string_array(char **array)
{
    size_t i = 0;

    if (array == NULL)
        return;

    while (array[i])
    {
        printf("INDEX[%ld]: %s\n", i, array[i]);
        i++;
    }
}

/**
 * search_array - searches a string array for strings which match terms
 * @array: an array of strings to be looked at
 * @length: number of items it contains
 * @search_terms: function pointer to criteria being used
 * 
 * Return: Double pointer to a new array containing matches
*/
char **search_array(char **array, size_t length, int (*terms)(const char*))
{
    char **matches;

    size_t i = 0;
    size_t j = 0;
    size_t num_of_hits = 0;

    for (i = 0; i < length; i++)
    {
        if (terms(array[i]))
            num_of_hits++;
    }

    matches = new_string_array(num_of_hits + 1);
    if (matches == NULL)
        return (NULL);

    for (i = 0; i < length; i++)
    {
        if (terms(array[i]))
        {
            matches[j] = _strdup(array[i]);
            j++;
        }
    }
    matches[num_of_hits] = NULL;

    return (matches);
}
