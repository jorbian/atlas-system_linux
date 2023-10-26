#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "socketlib.h"


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

/**
 * create_socket - create the listening socket for the sever
 * @fd: file descriptor to use for the new socket
 * @opt: which options need to be used.
 *
 * Return: Whether or not the scoket was created/
*/
int8_t create_socket(int *fd, int opt)
{
	*fd = socket(AF_INET, SOCK_STREAM, 0);
	if (*fd == 0)
		return (-1);

	if (setsockopt(
		*fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))
	)
		return (-1);

	return (0);
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
int8_t bind_socket(int *fd, saddr_t *addr, int family, int ip, int port)
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
int8_t take_connection(int *fd, saddr_t *addr)
{
	char buffer[DEFAULT_BUFF_SIZE] = {0};

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
		bytes_read = read(fd[CLIENT], buffer, DEFAULT_BUFF_SIZE);
		if (bytes_read < 0)
			return (-1);

		printf("Message received: \"%s\"\n", buffer);

		break;
	}
	return (0);
}

char *request_received(int client)
{
    char received[4096], sent[4096], *msgrcv;
    ssize_t bytes_read;
    size_t message_size = sizeof(sent);

    bytes_read = recv(client, received, sizeof(received), 0);
	if (bytes_read > 0)
	{
		msgrcv = received;
		printf("Raw request: \"%s\"\n", received);
        snprintf(sent, sizeof(sent),
             "HTTP/1.1 200 OK\r\n");
        send(client, sent, message_size, 0);
        close(client);
        fflush(stdout);
    }
    return (msgrcv);
}