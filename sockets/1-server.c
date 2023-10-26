#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#include "socketlib.h"

#define PORT 12345
#define MAX_CONNECTIONS 5

/**
 * fill_in_address - does exactly what it says on the tin
 * @address: pointer to the socket address struct
 * @port: the port we're suposed to be listening to
 *
*/
static void fill_in_address(saddr_t *address, int port)
{
	address->sin_family = AF_INET;
	address->sin_addr.s_addr = INADDR_ANY;
	address->sin_port = htons(port);
}

/**
 * setup_socket - initalizes and binds the server socket to port
 * @port: the port that it needs to start listening to
 *
 * Return: whether or not it was sucessfully bound
*/
int16_t setup_socket(int port)
{
	int16_t socket_fd;

	struct sockaddr_in address;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
		return (-1);

	fill_in_address(&address, port);

	bind(socket_fd, (struct sockaddr *)&address, sizeof(struct sockaddr_in));

	listen(socket_fd, MAX_CONNECTIONS);

	printf("Server listening on port %d...\n", PORT);

	return (socket_fd);
}

/**
 * take_request - processes whatever request there is...
 * @socket_fd: file descriptor of the server socket
 *
 * Return: Whether or not there was a problem.
*/
static int8_t take_request(int16_t *socket_fd)
{
	int16_t client_fd;
	saddr_t client_addr;

	unsigned int addr_len;

	addr_len = sizeof(client_addr);

	client_fd = accept(
		*socket_fd,
		(struct sockaddr *)&client_addr,
		(socklen_t *)&addr_len
	);
	if (client_fd < 0)
		return (-1);

	printf("IT GOT HERE");
	if (getpeername(
			client_fd,
			(struct sockaddr *)&client_addr,
			(socklen_t *)&addr_len
		) < 0)
		return (-1);

	printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

	close(client_fd);

	return (0);
}

/**
 * main - Entry point the server program
 *
 * Return: EXIT_SUCCESS or -1
*/
int main(void)
{
	int16_t socket_fd = setup_socket(PORT);

	while (1)
	{
		take_request(&socket_fd);
		break;
	}
	return (0);
}
