#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "socketlib.h"

int spinup_server(void)
{
	int server_fd;
	saddr_t addr;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
        return (-1);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(DEFAULT_PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr))< 0)
		return(-1);

	if (listen(server_fd, 8) < 0)
		return(-1);

	printf("Server listening on port %d\n", ntohs(addr.sin_port));

	while (1)
		accept_connection(server_fd, addr);
	
	close(server_fd);
}

int send_message(int client_fd)
{
	char *message = DEFAULT_MESSAGE;

	send(client_fd, message, strlen(message), 0);

	return (0);
}

int8_t accept_connection(int server_fd, saddr_t addr)
{
	int client_fd;
    int addrlen = sizeof(addr);

	client_fd = accept(
        server_fd, (struct sockaddr *)&addr, (socklen_t*)&addrlen
    );
	if (client_fd < 0)
		return(-1);

	printf("Client connected: %s\n", inet_ntoa(addr.sin_addr));
	break_print_request(client_fd);
	close(client_fd);
	return (-1);
}
