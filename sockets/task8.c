#include "socketlib.h"

/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, backlog = 8;
    client_info client;

	socketfd = initiate_socket();

	while (listen(socketfd, backlog) == 0)
	{
		
		client = accept_connection_api(socketfd);
		request_received_api(&client);
    
	}
	return (0);
}
