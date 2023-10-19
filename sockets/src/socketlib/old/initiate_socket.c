#include "socketlib.h"

/**
 * initiate_socket - initiate socket and bind it to an address
 * @family: asdf
 * @type: asdf
 * @ip: asdf
 * @port: asdf
 * 
 * Return: file descriptor to the socket (or -1)
*/
int initiate_socket(int family, int type, int ip, int port)
{
    int socketfd;

    struct sockaddr_in address;

    socketfd = socket(family, type, 0);

	address.sin_family = family;
	address.sin_addr.s_addr = ip;
    address.sin_port = htons(port);

	bind(socketfd, (struct sockaddr *)&address, sizeof(struct sockaddr_in));

    return (socketfd);
}
