#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    char buf[2000];
    int fd = open("nf_file.txt", O_RDONLY);
    size_t bytes = read(fd, buf, sizeof(buf) - 1);
    buf[bytes] = '\0';

    size_t num_lines = 0;
    char* lines[2000];

    char* pch;
    pch = strtok(buf, "\n");
    while (pch != NULL) {
        lines[num_lines++] = pch;
        pch = strtok(NULL, "\n");
    }

    size_t i;
    for (i = 0; i < num_lines; ++i) {
        pch = strtok(lines[i], ":");
        while (pch != NULL) {
            printf("%s\n", pch);
            pch = strtok(NULL, ":");
        }
    }
    for (i = 0; i < num_lines; ++i) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

