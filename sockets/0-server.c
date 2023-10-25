#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "sockets.h"

#define PORT 12345
#define MAX_CONNECTIONS 5

/**
 * fill_in_address - does exactly what it says on the tin
 * @address: pointer to the socket address struct
 * @family: asd fasdf
 * @ip: the ip address we're specifying
 * @port: the port we're suposed to be listening to
 *
*/
static void fill_in_address(struct sockaddr_in *address, uint16_t port)
{
	address->sin_family = AF_INET;
	address->sin_addr.s_addr = INADDR_ANY;
	address->sin_port = htons(port);
}


/**
 * initiate_socket - initalizes and binds the server socket to port
 * @fd: the file descriptor for the new socket
 * @port: the port that it needs to start listening to
 * 
 * Return: whether or not it was sucessfully bound
*/
int8_t initiate_socket(int16_t *fd, int16_t port)
{
	struct sockaddr_in address;

	*fd = socket(AF_INET, SOCK_STREAM, 0);
	if (*fd == -1)
		return (-1);

	fill_in_address(&address, port);

	bind(*fd, (struct sockaddr *)&address, sizeof(struct sockaddr_in));

	listen(*fd, MAX_CONNECTIONS);

	printf("Server listening on port %d...\n", PORT);

	return (0);
}

/**
 * main - Entry point the server program
 * Return: Always 0
*/
int main(void)
{
	int16_t sock_fd;

	initiate_socket(&sock_fd, PORT);

	for (;;)
		;

	close(sock_fd);

	return (EXIT_SUCCESS);
}
