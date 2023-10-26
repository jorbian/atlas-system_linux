#include "socketlib.h"

#ifndef PORT
    #define PORT 8080
#endif

/**
 * main - sets up a listening socket and accepts connections
 * Return: EXIT_SUCESS (i.e. 0)
*/
int main(void)
{
	int server_fd, client_fd;

	initiate_socket(&server_fd, PORT);

	while (start_listening(&server_fd, PORT) == 0)
	{
		
		accept_connection(&server_fd, &client_fd);
		request_received(&client_fd);
	}
	return (0);
}