#ifndef SOCKETLIB_H
#define SOCKETLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef struct sockaddr_in saddr_t;

int8_t initiate_socket(int16_t *fd, int16_t port);
int8_t start_listening(int16_t *fd, int16_t port);
void accept_connection(int16_t *server, int16_t *client);
void request_received(int16_t *client);

#endif
