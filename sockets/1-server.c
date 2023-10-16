#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "sockets.h"

#define PORT 12345
#define MAX_CONNECTIONS 5

static int server_socket, client;
static saddr_t server_addr, client_addr;
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

	return (EXIT_SUCCESS);
}

/**
 * take_request - processes whatever request there is...
 *
 * Return: Whether or not there was a problem.
*/
static int take_request(void)
{
	client = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
	if (client < 0)
		return (EXIT_FAILURE);

	if (getpeername(
			client,
			(struct sockaddr *)&client_addr,
			(socklen_t *)&addr_len
		) < 0)
		return (EXIT_FAILURE);

	printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

	close(client);

	return (EXIT_SUCCESS);
}

/**
 * main - Entry point the server program
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(void)
{
	int error_event;

	error_event = setup_socket(PORT);
	if (error_event)
		exit(EXIT_FAILURE);

	printf("Server listening on port %d...\n", ntohs(server_addr.sin_port));

	while (1)
	{
		take_request();
		break;
	}
	return (EXIT_SUCCESS);
}
