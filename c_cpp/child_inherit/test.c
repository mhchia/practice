#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE (1000)

int main(void)
{
    int fd;
    fd = open("test_file", 'r');
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        bzero(buffer, sizeof(buffer));
        int bytes = read(fd, buffer, sizeof(buffer));
        if (bytes < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "%s", buffer);
    }
    exit(EXIT_SUCCESS);
}
