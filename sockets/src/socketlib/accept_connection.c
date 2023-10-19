#include "socketlib.h"

int accept_connection(int socketfd)
{
    socklen_t *inbound_addrlength = calloc(1, sizeof(socklen_t));
    struct sockaddr *inbound_address = calloc(1, sizeof(struct sockaddr));
    struct sockaddr_in *inbound_address_in;
    int clientfd;

    *inbound_addrlength = (socklen_t)sizeof(struct sockaddr);
    clientfd = accept(socketfd, inbound_address, inbound_addrlength);
    inbound_address_in = (struct sockaddr_in *)inbound_address;
    printf("Client connected: %s\n", inet_ntoa(inbound_address_in->sin_addr));
    fflush(stdout);

    return (clientfd);
}

