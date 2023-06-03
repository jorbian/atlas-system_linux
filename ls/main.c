#include <stdio.h>
#include <dirent.h>
#include <string.h>

void main()
{
	DIR *dir;
	int is_not_dot;
	struct dirent *dp;
	char *file_name;

	dir = opendir(".");
	while ((dp=readdir(dir)) != NULL)
	{
		is_not_dot = !(!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."));
		if (is_not_dot)
		{
			file_name = dp->d_name;
			printf("file_name: '%s'\n", file_name);
		}
	}
	closedir(dir);
}
