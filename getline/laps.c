#include "laps.h"
/**
 * race_state - finction to keep track or laps made
 * @id: array of car identifiers
 * @size: size of array
*/

void race_state(int *id, size_t size)
{
	static car_list *new;

	if (size == 0)
	{
		free_list(new);
		return;
	}
	if (new == NULL)
	{
		size_t i;

		for (i = 0; i < size; i++)
			add_nodeint(&new, id[i], 0);
	}
	else
	{
		size_t i;

		for (i = 0; i < size; i++)
			check_id(&new, id[i]);
	}
	printf("Race state:\n");
	print_list(&new);
}

/**
 * print_list - prints list prints list of cars and the laps each car has made
 * @head: pointer to static variable
*/

void print_list(car_list **head)
{
	car_list *temp = *head;

	while (temp)
	{
		printf("Car %lu [%d laps]\n", temp->car, temp->lap);
		temp = temp->next;
	}
}

/**
 * add_nodeint - adds a node to the linked list
 * @head: pointer to address of linked list
 * @car: identifier of car
 * @lap: number of laps to initialize car with
 * Return: car_list struct
*/

car_list *add_nodeint(car_list **head, const int car, int lap)
{
	car_list *current;
	car_list *surfer;

	current = malloc(sizeof(car_list));
	if (!current)
	{
		free(current);
		return (NULL);
	}
	current->car = car;
	current->lap = lap;
	if (*head == NULL || (*head)->car >= current->car)
	{
		current->next = *head;
		*head = current;
		printf("Car %lu joined the race\n", current->car);
		return (*head);
	}
	else
	{
		surfer = *head;
		while (surfer->next != NULL && surfer->next->car < current->car)
			surfer = surfer->next;
	}
	current->next = surfer->next;
	surfer->next = current;
	printf("Car %lu joined the race\n", current->car);
	return (*head);
}
/**
 * free_list - frees the allocated memory
 * @head: pointer to linked list
*/
void free_list(car_list *head)
{
	car_list *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 * check_id - checks linked list to see if car is known
 * @head: pointer to address of linked list
 * @id: car id that is being checked for
*/
void check_id(car_list **head, size_t id)
{
	car_list *temp = *head;

	while (temp)
	{
		if (id == temp->car)
		{
			temp->lap = temp->lap + 1;
			temp = temp->next;
			break;
		}
		else if ((id != temp->car) && (temp->next == NULL))
		{
			add_nodeint(&(*head), id, 0);
			return;
		}
		temp = temp->next;
	}
}
