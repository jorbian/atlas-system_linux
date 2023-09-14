#include "multithreading.h"

/**
 * prime_factors - factorizes a number into list of prime factors
 * @string: the string representation of number being factorized
 *
 * Return: list_t list of prine factors
 */
list_t *prime_factors(char const *string)
{
	unsigned long num;
	unsigned long *cursor;
	unsigned long current_prime = 2;

	list_t *list = malloc(sizeof(list_t));

	if (!list)
		return (NULL);

	list_init(list);

	num = strtoul(string, NULL, 10);

	while (current_prime * current_prime <= num)
	{
		while (num % current_prime == 0)
		{
			cursor = malloc(sizeof(unsigned long));
			*cursor = current_prime;
			list_add(list, cursor);
			num /= current_prime;
		}
		current_prime += 1 + (current_prime != 2);
	}

	if (num >= 2)
	{
		cursor = malloc(sizeof(unsigned long));
		*cursor = num;
		list_add(list, cursor);
	}
	return (list);
}
