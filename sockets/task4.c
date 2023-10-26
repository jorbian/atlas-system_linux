#include "socketlib.h"

int main(void)
{
	return (spinup_server());
}

int16_t break_print_request(int16_t client_fd)
{
	char buffer[DEFAULT_BUFF_SIZE] = {0};
	char *method, *path, *http_version;

	read(client_fd, buffer, DEFAULT_BUFF_SIZE);
	printf("Raw request: \"%s", buffer);

	method = strtok(buffer, " ");
    path = strtok(NULL, " ");
    http_version = strtok(NULL, "\r\n");

	printf("\"\n");
	printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", http_version);

	return(send_message(client_fd));
}