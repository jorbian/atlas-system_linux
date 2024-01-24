#include <stdio.h>

#include "./inc/hls.h"

/**
 * main - entry point for program
 * @argc: number of arguments passed to program
 * @argv: the contents of those arguments
 *
 * Return: Always '0'--
*/
int main(int argc, char **argv)
{
    ls_t context;

    initalize_context((ls_t *)&context, argc, argv);
    get_child_items((ls_t *)&context);

    quick_sort(
        context.child_item_names,
        sizeof(const char *),
        0,
        context.num_children,
        string_compare
    );
    for (uint32_t i = 0; i < context.num_children; i++)
        printf("%s\n", context.child_item_names[i]);

    return (0);
}
