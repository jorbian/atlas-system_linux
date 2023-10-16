#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "sockets.h"

#define PORT 12345
#define MAX_CONNECTIONS 5

static int server_socket;
static saddr_t server_addr;
static socklen_t addr_len = sizeof(server_addr);

/**
 * setup_socket - procedure for setting up a socket we won't listen to
 * @port: number of the port being listened to
 *
 * Return: Whether or not there was a problem.
*/
static int setup_socket(int port)
{
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1)
		return (EXIT_FAILURE);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	if (bind(server_socket, (struct sockaddr *)&server_addr, addr_len) < 0)
		return (EXIT_FAILURE);

	if (listen(server_socket, MAX_CONNECTIONS) < 0)
		return (EXIT_FAILURE);

	printf("Server listening on port %d...\n", port);

	return (EXIT_SUCCESS);
}

/**
 * main - Entry point the server program
 * Return: Always 0
*/
int main(void)
{
	setup_socket(PORT);

	for (;;)
		;

	return (0);
}
