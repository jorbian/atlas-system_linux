#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * main - entry point for the function
 * Return: returns 0
*/
int main(void)
{
	DIR *dir;
	int is_not_dot = 0;
	struct dirent *dp;
	char *file_name;

	dir = opendir(".");
	while ((dp = readdir(dir)) != NULL)
	{
		file_name = dp->d_name;
		if (!(file_name[0] == '.'))
			printf("%s\n", file_name);
	}
	closedir(dir);

	return (0);
}
