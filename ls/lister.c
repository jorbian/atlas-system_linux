#include "hls.h"

/**
 * create_dir_lister - initalize the directory lister
 * @argc: num of args -- sent directly here from main
 * @argv: args passed to progrm -- again, sent directly here from main
 * 
 * Return: Data structure containing args sorted into program params.
*/
dir_ls *create_dir_lister(int argc, char **argv)
{
    dir_ls *new_ls;

    new_ls = malloc(sizeof(dir_ls));
    if (new_ls == NULL)
        return (NULL);

    new_ls->items_to_list = search_array(argv, argc, no_flag);
    new_ls->num_of_items = get_num_of_matches(argv, argc, no_flag);

    if (new_ls->items_to_list == NULL)
    {
        free(new_ls);
        return (NULL);
    }
    new_ls->flag_token = '\0';

    return (new_ls);
}

/**
 * activate_lister - active the directory lister
 * @ls: the data struct containing the sorted paramaters
 * 
*/
void activate_lister(dir_ls *ls)
{
    size_t num_of_items = ls->num_of_items;

    if (ls->flag_token == '\0')
    {
        if (num_of_items == 1)
            simple_listing(".");
        else
            simple_listing(ls->items_to_list[1]);
    }
}

/**
 * deinitilize_dir_lister - free everything inside lister than lister itself
 * @ls: the directory lister data structure
*/
void deinitilize_dir_lister(dir_ls *ls)
{
    if (ls->items_to_list)
        free_string_array(ls->items_to_list);

    free(ls);
}
