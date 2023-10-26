#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int list_t;

#define DEFAULT_PORT 8080
#define DEFAULT_BUFF_SIZE 1024
#define DEFAULT_MESSAGE "HTTP/1.1 200 OK\n"
#define ELEMENT_SIZE 4
#define LIST_SIZE 16384
#define GET_MAX_SIZE(list) ((int16_t *)list)[0]
#define GET_CURR_SIZE(list) ((int16_t *)list)[1]
#define LEN(list) GET_CURR_SIZE(list) / ELEMENT_SIZE

int16_t append(int32_t *list, int32_t item)
{
    int16_t max, current, length;

    int16_t *current_size = &GET_MAX_SIZE(list) + 1;

    if ((GET_CURR_SIZE(list) + ELEMENT_SIZE) >= GET_MAX_SIZE(list))
        return (-1);

    length = LEN(list);

    list[length] = item;

    *current_size = *current_size + ELEMENT_SIZE;

    length++;

    return (length);
}

void initalize_list(int32_t *list, int32_t max_size)
{
    *((int16_t *)list) = max_size;
    *((int16_t *)list + 1) = 4;
}
