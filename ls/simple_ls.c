#include <stdio.h>
#include <stdlib.h>

void simple_ls(void) {
    const char *command = "ls";
    char shell_command[256];

    sprintf(shell_command, "/bin/sh -c '%s'", command);
    system(shell_command);
}

int main() {
    simple_ls();
    return 0;
}
