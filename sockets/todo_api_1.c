#include "inc/socketlib.h"

static void task5_breakdown(void *message_received)
{
    char *token, *querystrg;
    
    token = (char *)message_received;
    token = strtok(token, " ");
    token = strtok(NULL, " ");
    querystrg = strdup(token);
    querystrg = strtok(querystrg, "?");
    printf("Path: %s\n", querystrg);
    querystrg = strtok(NULL, "=");
    while(querystrg)
    {
        
        printf("Query: \"%s\" -> ", querystrg);
        querystrg = strtok(NULL, "&\n\r");
        printf("\"%s\"\n", querystrg);
        querystrg = strtok(NULL, "=");
    }
    fflush(stdout);
}

/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, clientfd, backlog = 8;
    char *msgrcv;

	socketfd = initiate_socket(AF_INET, SOCK_STREAM, INADDR_ANY, 8080);
	printf("Server listening on port 8080\n");
	while (listen(socketfd, backlog) == 0)
	{
		
		clientfd = accept_connection(socketfd);
		msgrcv = request_received(clientfd);
        task5_breakdown(msgrcv);
	}
	return (0);
}