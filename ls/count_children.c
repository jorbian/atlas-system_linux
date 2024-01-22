#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdint.h>

#define MAX_PATH_LEN 1025
#define FOLDER_NAME "/home/boller/code/atlas-system_linux/ls"

static char **allocate_buffer(uint64_t size)
{
    uint64_t i;

    char **new_buffer;

    new_buffer = (
        (char **)malloc(size * sizeof(char *))
    );

    if (new_buffer)
        for (i = 0; i < size; i++)
            new_buffer[i] = (char *)malloc(MAX_PATH_LEN);

}

static uint64_t count_items(const char *folder)
{
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    if ((dir = opendir(folder)) != NULL)
        while ((ent = readdir(dir)) != NULL)
            count++;
        
    closedir(dir);

    return (count);
}
int main() {
    DIR *dir;
    struct dirent *ent;

    int count = count_items(FOLDER_NAME);

    dir = opendir(FOLDER_NAME);

    char **fileNames = (char **)malloc(count * sizeof(char *));
    for (int i = 0; i < count; i++) {
        fileNames[i] = (char *)malloc(MAX_PATH_LEN); // Adjust MAX_PATH accordingly
    }

    int index = 0;
    while ((ent = readdir(dir)) != NULL) {
        snprintf(fileNames[index], MAX_PATH_LEN, "%s", ent->d_name);
        index++;
    }

        // Close the directory
        closedir(dir);

        // Now fileNames array contains the names of all items in the folder

        // Use fileNames array as needed

        // Don't forget to free the allocated memory
        for (int i = 0; i < count; i++) {
            printf("%s\n", fileNames[i]);
            free(fileNames[i]);
        }
        free(fileNames);

    return 0;
}
