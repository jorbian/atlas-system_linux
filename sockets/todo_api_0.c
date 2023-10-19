#include "socketlib.h"

/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, clientfd, backlog = 8;

	socketfd = initiate_socket(AF_INET, SOCK_STREAM, INADDR_ANY, 8080);
	printf("Server listening on port 8080\n");
	while (listen(socketfd, backlog) == 0)
	{
		
		clientfd = accept_connection(socketfd);
		request_received(clientfd);
	}
	return (0);
}
