#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#include "socketlib.h"

enum fd_indecies
{
	SERVER, NEW_SOCKET, CLIENT
};

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


/**
 * throw_error - write error message to stderr and peace out
 * @error_type: a predefined error message
 * @detail: detail to fill into that message
 *
*/
static void throw_error(const char *error_type, const char *detail)
{
	fprintf(stderr, error_type, detail);
	exit(EXIT_FAILURE);
}

/**
 * parse_args - parses arguments given to program and moves them into place
 * @argv: arguments passed to the program
 * @host: string to store the host name
 * @port: port number we're connecting to
 *
*/
static void parse_args(char **argv, char *host, int *port)
{
	if (!argv[1] || !argv[2])
		throw_error("Usage: %s <host> <port>\n", argv[0]);

	*port = strtol(argv[2], NULL, 10);

	if (*port <= 0)
		throw_error("Invalid port number: %s\n", argv[2]);

	strcpy(host, argv[1]);
}

/**
 * prep_connection - prepare the connection
 * @connection: the connection struct we're working on.
 * @host: the hostname
 * @port: the port number we're going to listen to
 *
*/
static void prep_connection(connect_t *connection, char *host, int port)
{
	connection->sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (connection->sock_fd < 0)
		throw_error("%ssocket create error\n", "");

	connection->server_addr.sin_family = AF_INET;
	connection->server_addr.sin_port = htons(port);

	connection->host_addr = gethostbyname(host);

	inet_pton(
		AF_INET,
		inet_ntoa(
			*(struct in_addr *)connection->host_addr->h_addr
		),
		&connection->server_addr.sin_addr
	);
}

/**
 * activate_connection - prepare the connection
 * @connection: the connection struct we're working on.
 *
*/
static void activate_connection(connect_t *connection)
{
	if (connect(
		connection->sock_fd,
		(struct sockaddr *)&(connection->server_addr),
		sizeof(connection->server_addr)
	) == -1)
		throw_error("%sclient socket connect error", "");

}

/**
 * main - entry point to progran
 * @argc: number of arguments fed to program
 * @argv: contents of the program
 *
 * Return: 0 for success, 1 upon failure
 */
int main(int argc, char **argv)
{
	int port;
	char host[255];
	connect_t connection;

	(void)argc;

	parse_args(argv, host, &port);
	prep_connection(&connection, host, port);
	activate_connection(&connection);

	fprintf(stdout, "Connected to %s:%d\n", host, port);

	close(connection.sock_fd);
	return (EXIT_SUCCESS);
}
