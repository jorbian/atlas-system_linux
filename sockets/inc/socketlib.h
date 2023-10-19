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

#define MSG_BUFF_SIZE 4096

int accept_connection(int socketfd);
int initiate_socket();
char *request_received(int clientfd);
void requst_breakdown(void *message_received);

#endif
