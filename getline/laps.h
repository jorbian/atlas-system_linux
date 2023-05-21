#ifndef LAPS_H
#define LAPS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct racer_t - holds each car's data
 * @car: id of car
 * @lap: laps made by car
 * @next: next car in list
 * Description: singly linked list struct
*/
typedef struct racer_t
{
	size_t car;
	int lap;
	struct list_t *next;
} racer;

/**
 * struct racer_list_t - holds each car's data
 * @first_car: pointer to data on first car
 * 
 * Description: singly linked list struct
*/
typedef struct racer_list_t
{
	struct list_t *first;
} racer_list;



void check_id(car_list **head, size_t id);
void free_list(car_list *head);
void print_list(car_list **head);
car_list *add_nodeint(car_list **head, const int car, int lap);
void race_state(int *id, size_t size);

#endif
