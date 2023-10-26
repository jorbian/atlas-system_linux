#include "socketlib.h"

int main(void)
{
	return (spinup_server());
}

int break_print_request(int client_fd)
{
	char buffer[DEFAULT_BUFF_SIZE] = {0};
	char *DELIMITER = " \t\r\n";
	char *path, *query, *save1, *save2, *key, *value;

	read(client_fd, buffer, DEFAULT_BUFF_SIZE);
	printf("Raw request: \"%s", buffer);

	strtok(buffer, DELIMITER);
	path = strtok(NULL, DELIMITER);
	path = strtok_r(path, "?", &save1);
	printf("\"\nPath: %s\n", path);

	query = strtok_r(NULL, "&", &save1);
	while(query)
	{
		key = strtok_r(query, "=", &save2);
		value = strtok_r(NULL, "=", &save2);
		printf("Query: \"%s\" -> \"%s\"\n", key, value);
		query = strtok_r(NULL, "&", &save1);
	}
	return (send_message(client_fd));
}
