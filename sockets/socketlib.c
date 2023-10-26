#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "socketlib.h"

#ifndef PORT
    #define PORT 8080
#endif

#define MAX_CONNECTIONS 5

/**
 * fill_in_address - does exactly what it says on the tin
 * @address: pointer to the socket address struct
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

	if (bind(
            *fd,
            (struct sockaddr *)&address,
            sizeof(struct sockaddr_in)
        ) == -1)
        return (-1);

	return (0);
}

int8_t start_listening(int16_t *fd, int16_t port)
{
    if (listen(*fd, MAX_CONNECTIONS) == -1)
        return (-1);

	printf("Server listening on port %d...\n", port);

    return (0);
}

void accept_connection(int16_t *server, int16_t *client)
{
    struct sockaddr *inbound_address;
    struct sockaddr_in *inbound_address_in;

    socklen_t addr_len = sizeof(struct sockaddr);

    *client = accept(*server, inbound_address, &addr_len);

    inbound_address_in = (struct sockaddr_in *)inbound_address;

    printf("Client connected: %s\n", inet_ntoa(inbound_address_in->sin_addr));

    fflush(stdout);
}

void request_received(int16_t *client)
{
    char message_received[8162], message_sent[8162];
    ssize_t byte_received;
    int16_t message_size = sizeof(message_sent);

    byte_received = recv(*client, message_received, sizeof(message_received), 0);
	if (byte_received > 0)
	{
		printf("Raw request: \"%s\"\n", message_received);
        snprintf(message_sent, sizeof(message_sent),
             "HTTP/1.1 200 OK\r\n");
        send(*client, message_sent, message_size, 0);
        close(*client);
        fflush(stdout);
    }
}