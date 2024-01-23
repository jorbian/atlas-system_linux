#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

#include "./inc/hls.h"

static char error_message[MAX_PATH_LEN];

static char *template_strings[] = {
	#define ERROR_TYPE(x, y) y,
		#include "./inc/error_type.def"
	#undef ERROR_TYPE
};

/**
 * find_msb - calculate the most significant bit of num
 * @num: an unsigned 32-bit integer
 *
 * Return: Whatever it's most signifcant bit is
*/
static uint32_t find_msb(uint32_t num)
{
	uint32_t i;

	for (i = 0; i <= SHIFT_RIGHT; i++)
		num |= num >> (1 << i);

	num = (
		((num + 1) >> 1) |
		(num & (1 << ((sizeof(num) * CHAR_BIT) - 1)))
	);
	return (num);
}

/**
 * determine_error_type - calculate the value of the error type
 * @error_num: error message number.
 *
 * Return: solution to the equation 2 ^ x = find_msb(error_num)
*/
static uint32_t determine_error_type(uint32_t error_num)
{
	uint32_t exponent = 0;

	uint32_t msb = find_msb(error_num);

	while (exponent < NUM_ERROR_TYPES)
	{
		if (msb & (1 << exponent))
			return (exponent);
		exponent++;
	}
	return (0);
}

/**
 * generate_error_message - generate an appropriate error message
 * @context: pointer to the ls_t context struct
 * @info: error info
 *
*/
void generate_error_message(ls_t *context, uint32_t info)
{
	char template[MAX_PATH_LEN], fields[3][DEFAULT_BUFF_SIZE];

	uint32_t error_type = determine_error_type(info);
	
	strncpy(template, template_strings[error_type], DEFAULT_BUFF_SIZE);

	strncpy(fields[0], context->app_name, DEFAULT_BUFF_SIZE);
	strncpy(fields[1], context->folder, DEFAULT_BUFF_SIZE);
	strncpy(fields[2], "", DEFAULT_BUFF_SIZE);

	sprintf(error_message, template, fields[0], fields[1], fields[2]);
}
/**
 * throw_error - determine the details of an error, display a message and exit
 * @context: pointer to the ls_t context struct
 *
*/
void throw_error(ls_t *context)
{
	uint32_t *error_info = &(context->error_info);

	generate_error_message(context, *error_info);

	fprintf(stderr, "%s", error_message);

	exit(1);
}
