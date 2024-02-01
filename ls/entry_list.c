#include "hls.h"

#define LIST_EMPTY(l) (!*l)

/**
 * create_empty_node - allocates memory for list node and initalizes values
 *
 * Return: Pointer to the newly allocated node.
*/
static entry_t *create_empty_node()
{
	entry_t *new = NULL;

	new = malloc(sizeof(entry_t));
	if (!new)
		return (NULL);

	new->name = NULL;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * add_to_list - adds the item to where its supposed to go on list in ABC ord
 * @list: double pointer to the top node of an entry list
 * @new_node: pointer to the newly allocated node
 *
 * Return: Whether or not there was a problem.
*/
static int add_to_list(entry_t **list, entry_t *new_node)
{
	int diff = 0;

	entry_t *tmp = NULL;

	if (LIST_EMPTY(list))
	{
		*list = new_node;
		return (0);
	}
	diff = _strcmp(new_node->name, (*list)->name);

	if (diff < 0 && diff != -32)
	{
		new_node->next = *list;
		(*list)->prev = new_node;
		*list = new_node;
		return (0);
	}

	for (tmp = *list; tmp; tmp = tmp->next)
	{
		diff = _strcmp(new_node->name, tmp->name);
		if (tmp->next && _strcmp(new_node->name, tmp->next->name) < 0)
			continue;
		new_node->next = tmp->next;
		new_node->prev = tmp;
		if (tmp->next)
			tmp->next->prev = new_node;
		tmp->next = new_node;
		break;
	}
	return (0);
}

/**
 * add_to_entry_list - populate command data dir list
 * @filename: name of directory to be added to list
 * @list: double pointer to the top node of an entry list
 *
 * Return: -1 upon memory allocation failure, 0 otherwise
*/
int add_to_entry_list(char *filename, entry_t **list)
{
	entry_t *new_node;

	new_node = create_empty_node();

	if (!new_node)
		return (-1);

	new_node->name = _strdup(filename);

	add_to_list(list, new_node);

	return (0);
}

/**
 * free_list - where the magic really happens freeing list
 * @llist: double pointer to the top node of an entry list
 *
*/
static void free_list(entry_t **llist)
{
	entry_t *temp = *llist, *current = NULL;

	if (temp)
		for (; temp;)
		{
			current = temp;
			temp = temp->next;
			if (current->name)
				free(current->name), current->name = NULL;
			free(current), current = NULL;
		}
}

/**
 * free_cdt - free all memory related to command data
 * @d_list: pointer to beginning of allocated memory for dir list
 * @f_list: pointer to beginning of allocated memory for file list
*/
void free_cdt(entry_t **d_list, entry_t **f_list)
{
	free_list(d_list);
	free_list(f_list);
}
