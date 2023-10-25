#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
static void fill_in_address(saddr_t *address, int family, int ip, int port)
{
	address->sin_family = family;
	address->sin_addr.s_addr = ip;
	address->sin_port = htons(port);
}

/**
 * initiate_socket - initiate socket and bind it to an address
 * @family: asdf
 * @type: asdf
 * @ip: asdf
 * @port: asdf
 *
 * Return: file descriptor to the socket (or -1)
*/
int initiate_socket(int family, int type, int ip, int port)
{
	int new_sock_fd;

	saddr_t address;

	new_sock_fd = socket(family, type, 0);
	if (new_sock_fd == -1)
		return (new_sock_fd);

	fill_in_address(&address, family, ip, port);

	if (
		bind(
			new_sock_fd,
			(struct sockaddr *)&address,
			sizeof(struct sockaddr_in)
		) == -1
	)
		return (-1);

	if (listen(new_sock_fd, MAX_CONNECTIONS) == -1)
		return (-1);

	return (new_sock_fd);
}
