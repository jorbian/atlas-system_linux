#include "inc/socketlib.h"

static void task6_breakdown(void *message_received)
{
    char *token, *host, *host_value, *user_agent, *agent_value, *ok, *slash;

    host = malloc(sizeof(char) * 32);
    host_value = malloc(sizeof(char) * 32);
    user_agent = malloc(sizeof(char) * 32);
    agent_value = malloc(sizeof(char) * 32);
    ok = malloc(sizeof(char) * 32);
    slash = malloc(sizeof(char) * 32);
    token = (char *)message_received;
    token = strtok(token, " ");
    token = strtok(NULL, "\n");
    token = strtok(NULL, " ");
    host = strdup(token);
    token = strtok(NULL, "\n");
    agent_value = strdup(token);
    host_value = strdup(token);
    user_agent = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " \n");
    ok = strdup(token);
    token = strtok(NULL, " \r");
    slash = strdup(token);
    slash[3] = '\"';
    slash[4] = '\0';
    printf("Header: \"%s\"", user_agent);
    printf(" -> \"%s\"\n", agent_value);
    printf("Header: \"%s\"", host);
    printf(" -> \"%s\"\n", host_value);
    printf("Header: \"%s\"", ok);
    printf(" -> \"%s\"\n", slash);
    fflush(stdout);
}


/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, clientfd, backlog = 8;
    char * msgrcv;

    socketfd = initiate_socket();
	printf("Server listening on port 8080\n");
	while (listen(socketfd, backlog) == 0)
	{
		
		clientfd = accept_connection(socketfd);
		msgrcv = request_received(clientfd);
        task6_breakdown(msgrcv);
	}
	return (0);
}