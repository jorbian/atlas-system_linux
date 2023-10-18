#ifndef SOCKETS_H
#define SOCKETS_H


/**
 * struct connection_s - struct that represents a network connection
 * @sock_fd: file descriptor for the connection socket
 * @server_addr: nested struct for server_addr
 * @host_addr: asdf asdf
*/
typedef struct connection_s {
    int sock_fd;
	struct sockaddr_in server_addr;
	struct hostent *host_addr;
} connect_t;

#endif
