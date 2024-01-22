#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 1025
#define FOLDER_NAME "/home/boller/code/atlas-system_linux/ls"



int main()
{
    DIR *dir;
    struct dirent *entry;
    char path_buff[MAX_PATH_LEN];
    char *fn = FOLDER_NAME;

    if ((dir = opendir(fn)) == NULL)
        return (0);

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.')
        {
            sprintf(path_buff, "%s/%s", fn, entry->d_name);
            printf("%s\n", path_buff);
        }
    }
}