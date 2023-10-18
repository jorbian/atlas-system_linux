#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "sockets.h"

#define PORT 12345
#define BUFF_SIZE 1024

/**
 * create_socket - create the listening socket for the sever
 * @fd: file descriptor to use for the new socket
 * @opt: which options need to be used.
*/
static void create_socket(int *fd, int opt)
{
	*fd = socket(AF_INET, SOCK_STREAM, 0);
	if (*fd == 0)
		exit(EXIT_FAILURE);

	if (setsockopt(
		*fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))
	)
		exit(EXIT_FAILURE);
}

/**
 * bind_socket - bind the socket to listen at specific address and port
 * @fd: pointer to the file descriptor of the socket we're binding
 * @addr: pointer to the address struct
 * @family: value corresponding to address family of socket
 * @ip: value corresponding to the address we are listening on
 * @port: which port needs to be listend on.
*/
static void bind_socket(int *fd, saddr_t *addr, int family, int ip, int port)
{
	addr->sin_family = family;
	addr->sin_addr.s_addr = ip;
	addr->sin_port = htons(port);

	if (bind(*fd, (struct sockaddr *)addr, sizeof(*addr)) < 0)
		exit(EXIT_FAILURE);

	if (listen(*fd, 3) < 0)
		exit(EXIT_FAILURE);

	printf("Server listening on port %d\n", port);
}

/**
 * take_connection - accept and process incomnig connection
 * @fd: file descriptor array
 * @addr: address server socket it bound to
 *
 */
static void take_connection(int *fd, saddr_t *addr)
{
	char buffer[BUFF_SIZE] = {0};

	size_t addrlen, bytes_read;

	addrlen = sizeof(*addr);

	while (1)
	{
		fd[NEW_SOCKET] = accept(
			fd[SERVER],
			(struct sockaddr *)addr,
			(socklen_t *)&addrlen
		);
		if (fd[NEW_SOCKET] < 0)
		{
			perror("accept failed");
			exit(EXIT_FAILURE);
		}
		printf("Client connected: %s\n", inet_ntoa(addr->sin_addr));
		fd[CLIENT] = fd[NEW_SOCKET]; /** Receive data from the client */
		bytes_read = read(fd[CLIENT], buffer, BUFF_SIZE);
		if (bytes_read < 0)
			exit(EXIT_FAILURE);
		printf("Message received: \"%s\"\n", buffer); /** Print the message */
		close(fd[NEW_SOCKET]); /** Close the connection */
		close(fd[CLIENT]);
		exit(EXIT_SUCCESS);
	}
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
}
