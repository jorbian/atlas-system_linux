#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "socketlib.h"

#define PORT 12345
#define BUFF_SIZE 1024

/**
 * create_socket - create the listening socket for the sever
 * @fd: file descriptor to use for the new socket
 * @opt: which options need to be used.
 *
 * Return: Whether or not the scoket was created/
*/
static int8_t create_socket(int *fd, int opt)
{
	*fd = socket(AF_INET, SOCK_STREAM, 0);
	if (*fd == 0)
		return (-1);

	if (setsockopt(
		*fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))
	)
		return (-1);
}

/**
 * bind_socket - bind the socket to listen at specific address and port
 * @fd: pointer to the file descriptor of the socket we're binding
 * @addr: pointer to the address struct
 * @family: value corresponding to address family of socket
 * @ip: value corresponding to the address we are listening on
 * @port: which port needs to be listend on.
 *
 * Return: Whether or not the socked was bound.
*/
static int8_t bind_socket(int *fd, saddr_t *addr, int family, int ip, int port)
{
	addr->sin_family = family;
	addr->sin_addr.s_addr = ip;
	addr->sin_port = htons(port);

	if (bind(*fd, (struct sockaddr *)addr, sizeof(*addr)) < 0)
		return (-1);

	if (listen(*fd, 3) < 0)
		return (-1);

	printf("Server listening on port %d\n", port);

	return (0);
}

/**
 * take_connection - accept and process incomnig connection
 * @fd: file descriptor array
 * @addr: address server socket it bound to
 *
 * Return: Whether or not there was a problem.
 */
static int8_t take_connection(int *fd, saddr_t *addr)
{
	char buffer[BUFF_SIZE] = {0};

	ssize_t addrlen, bytes_read;

	addrlen = sizeof(*addr);

	while (1)
	{
		fd[NEW_SOCKET] = accept(
			fd[SERVER],
			(struct sockaddr *)addr,
			(socklen_t *)&addrlen
		);
		if (fd[NEW_SOCKET] < 0)
			return (-1);

		printf("Client connected: %s\n", inet_ntoa(addr->sin_addr));

		fd[CLIENT] = fd[NEW_SOCKET];
		bytes_read = read(fd[CLIENT], buffer, BUFF_SIZE);
		if (bytes_read < 0)
			return (-1);

		printf("Message received: \"%s\"\n", buffer);
		close(fd[NEW_SOCKET]);
		close(fd[CLIENT]);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
/**
 * main - entry point for socket listener
 * Return: 0 on success, 1 upon failure
 */
int main(void)
{
	int fd[3];
	saddr_t address;

	create_socket(&fd[SERVER], 1);
	bind_socket(&fd[SERVER], &address, AF_INET, INADDR_ANY, PORT);
	take_connection(&fd[SERVER], &address);

	return (0);
}
