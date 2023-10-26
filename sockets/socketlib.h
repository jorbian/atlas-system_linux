#ifndef SOCKETLIB_H
#define SOCKETLIB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define DEFAULT_PORT 8080
#define DEFAULT_BUFF_SIZE 1024
#define DEFAULT_MESSAGE "HTTP/1.1 200 OK\n"
#define ELEMENT_SIZE 4
#define LIST_SIZE 16384
#define GET_MAX_SIZE(list) ((int16_t *)list)[0]
#define GET_CURR_SIZE(list) ((int16_t *)list)[1]
#define LEN(list) GET_CURR_SIZE(list) / ELEMENT_SIZE

typedef int list_t;

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

enum fd_indecies
{
	SERVER, NEW_SOCKET, CLIENT
};

typedef struct sockaddr_in saddr_t;

char *request_received(int client);
int8_t take_connection(int *fd, saddr_t *addr);
int8_t bind_socket(int *fd, saddr_t *addr, int family, int ip, int port);
int8_t create_socket(int *fd, int opt);
void initalize_list(int32_t *list, int32_t max_size);
int16_t append(int32_t *list, int32_t item);

#endif
