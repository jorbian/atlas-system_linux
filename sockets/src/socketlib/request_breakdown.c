#include "socketlib.h"

void requst_breakdown(void *message_received)
{
    char *token;
    token = (char *)message_received;
    token = strtok(token, " ");
    printf("Method: %s\n", token);
    token = strtok(NULL, " ");
    printf("Path: %s\n", token);
    token = strtok(NULL, " \r\n");
    printf("Version: %s\n", token);
    fflush(stdout);
}
