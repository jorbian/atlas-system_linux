#include "socketlib.h"

int initiate_socket()
{
    int socketfd;
    struct sockaddr_in *address;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
	address = calloc(1, sizeof(struct sockaddr_in));
	address->sin_family = AF_INET;
	address->sin_port = htons(8080);
	address->sin_addr.s_addr = INADDR_ANY;
	bind(socketfd, (struct sockaddr *)address, sizeof(struct sockaddr_in));

    return (socketfd);
}
