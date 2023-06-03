#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main()
{
	DIR *dir;
	struct dirent *dp;
	char *file_name;

	dir = opendir(".");
	while ((dp=readdir(dir)) != NULL)
	{
		file_name = dp->d_name;
		printf("%s\n", file_name);
	}
	closedir(dir);

	return (0);
}
