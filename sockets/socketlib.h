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

int16_t spinup_server(void);
int8_t accept_connection(int16_t server_fd, saddr_t addr);
int16_t send_message(int16_t client_fd);
int16_t break_print_request(int16_t client_fd);

#endif
