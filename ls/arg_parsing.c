#include "my_strings.h"


/**
 * contains_flag - used to find flag arguments
 * arg_value - string cointing argv value
 * 
 * Return: '1' for True, the value is 45, '0' for False.
*/
int contains_flag(const char *arg_value)
{
    return (FIRST_CHAR(arg_value) == 45);
}

/**
 * no_flag - used to find flag arguments
 * arg_value - string cointing argv value
 * 
 * Return: '0' for True, the value is 45, '1' for False.
*/
int no_flag(const char *arg_value)
{
    return ((FIRST_CHAR(arg_value) != 45) && (NTH_CHAR(arg_value, 1) != 47));
}
