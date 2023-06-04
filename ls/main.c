#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024

void print_file_info(const char *filename) {
    struct stat file_stats;
    if (lstat(filename, &file_stats) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    struct passwd *user = getpwuid(file_stats.st_uid);
    struct group *group = getgrgid(file_stats.st_gid);
    char permissions[11];

    // Get file permissions
    permissions[0] = (S_ISDIR(file_stats.st_mode)) ? 'd' : '-';
    permissions[1] = (file_stats.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (file_stats.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = (file_stats.st_mode & S_IXUSR) ? 'x' : '-';
    permissions[4] = (file_stats.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (file_stats.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = (file_stats.st_mode & S_IXGRP) ? 'x' : '-';
    permissions[7] = (file_stats.st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (file_stats.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = (file_stats.st_mode & S_IXOTH) ? 'x' : '-';
    permissions[10] = '\0';

    char mod_time[20];
    strftime(mod_time, sizeof(mod_time), "%b %d %H:%M", localtime(&file_stats.st_mtime));

    printf("%s %2ld %s %s %5ld %s %s\n", permissions, file_stats.st_nlink, user->pw_name, group->gr_name,
           file_stats.st_size, mod_time, filename);
}

void list_directory(const char *directory_path) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory_path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        char file_path[MAX_PATH_LENGTH];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
        print_file_info(file_path);
    }

    if (closedir(dir) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    list_directory(argv[1]);

    return 0;
}
