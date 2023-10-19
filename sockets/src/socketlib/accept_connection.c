#include "socketlib.h"

int accept_connection(int socketfd)
{
    int clientfd;

    struct sockaddr *inbound_address = NULL;
    struct sockaddr_in *inbound_address_in = NULL;

    socklen_t inbound_addrlength = sizeof(struct sockaddr);

    inbound_addrlength = sizeof(struct sockaddr);
    clientfd = accept(socketfd, inbound_address, &inbound_addrlength);
    inbound_address_in = (struct sockaddr_in *)inbound_address;
    printf("Client connected: %s\n", inet_ntoa(inbound_address_in->sin_addr));
    fflush(stdout);

    return (clientfd);
}

