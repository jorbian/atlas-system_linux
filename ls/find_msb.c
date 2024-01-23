#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/**
 * find_msb - calculates the most significant bit of n
 * @n: an unsigned 32-bit integer
 * 
 * Return: Whatever it's most signifcant bit is
*/
uint32_t find_msb(uint32_t n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    n = (
        ((n + 1) >> 1) |
        (n & (1 << ((sizeof(n) * CHAR_BIT)-1)))
    );

    return (n);
}
