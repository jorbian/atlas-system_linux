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

#endif
