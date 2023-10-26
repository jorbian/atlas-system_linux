#ifndef SOCKETLIB_H
#define SOCKETLIB_H

#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080
#define DEFAULT_BUFF_SIZE 1024
#define DEFAULT_MESSAGE "HTTP/1.1 200 OK\n"

/**
 * struct connection_s - struct that represents a network connection
 * @sock_fd: file descriptor for the connection socket
 * @server_addr: nested struct for server_addr
 * @host_addr: asdf asdf
*/
typedef struct connection_s
{
	int sock_fd;
	struct sockaddr_in server_addr;
	struct hostent *host_addr;
} connect_t;

typedef struct sockaddr_in saddr_t;

int spinup_server(void);
int8_t accept_connection(int server_fd, saddr_t addr);
int send_message(int client_fd);
int break_print_request(int client_fd);

#endif
