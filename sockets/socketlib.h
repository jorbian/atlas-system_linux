#ifndef SOCKETLIB_H
#define SOCKETLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>

#define DEFAULT_BUFF_SIZE 1024
#define DEFAULT_MESSAGE "HTTP/1.1 200 OK\n"

typedef struct sockaddr_in saddr_t;

int spinup_server(void);
int8_t accept_connection(int server_fd, saddr_t addr);
int send_message(int client_fd);
int break_print_request(int client_fd);

#endif
