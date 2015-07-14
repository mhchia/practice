#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    char buf[1024] = {0};

    pid_t pid;

    while (1) {
        printf("minibash$ ");
        scanf("%s", buf);
        pid = fork();
        if (pid == 0) { // child
            if (execlp(buf, 0) < 0) {
                fprintf(stderr, "exec error\n");
            }
        } else if (pid > 0) {
            int status;
            waitpid(pid, status, 0);
        } else {
            fprintf(stderr, "fork error %d\n", pid);
        }
    }
    return 0;
}

