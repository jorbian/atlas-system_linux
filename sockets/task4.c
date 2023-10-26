#include "socketlib.h"

#ifndef PORT
    #define PORT 8080
#endif

/**
 * main - sets up a listening socket and accepts connections
 * Return: EXIT_SUCESS (i.e. 0)
*/
int main(void)
{
    int fd[3];
	saddr_t address;

    create_socket(&fd[SERVER], 1);
    bind_socket(&fd[SERVER], &address, AF_INET, INADDR_ANY, PORT);

    while (1)
    {
        take_connection(&fd, &address);
        request_received(&fd[CLIENT])
    }
	return (0);
}
