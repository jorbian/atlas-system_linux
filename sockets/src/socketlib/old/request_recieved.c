#include "socketlib.h"

char *request_received(int clientfd)
{
    char message_received[MSG_BUFF_SIZE], message_sent[MSG_BUFF_SIZE];
    char *msgrcv;

    ssize_t byte_received;
    size_t message_size = sizeof(message_sent);

    byte_received = recv(clientfd, message_received, sizeof(message_received), 0);
	if (byte_received > 0)
	{
		msgrcv = message_received;
		printf("Raw request: \"%s\"\n", message_received);
        snprintf(message_sent, sizeof(message_sent),
             "HTTP/1.1 200 OK\r\n");
        send(clientfd, message_sent, message_size, 0);
        close(clientfd);
        fflush(stdout);
    }
    return (msgrcv);
}
