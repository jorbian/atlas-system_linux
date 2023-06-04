#include <stdio.h>

void simple_ls(void) {
    FILE *pipe = popen("ls", "r");
    if (pipe) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            printf("%s", buffer);
        }
        pclose(pipe);
    } else {
        perror("popen");
    }
}

int main() {
    simple_ls();
    return 0;
}
