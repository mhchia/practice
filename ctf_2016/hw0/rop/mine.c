#include <stdio.h>
#include <time.h>


int len;

int service()
{
    int result;
    char buf[0x01];
    if (read(0, buf, len) > 0) {
        puts(buf);
        result = 0;
    } else {
        result = -1;
    }
    return result;
}

int z()
{
//    return 80;
    return time(0) - 1456113600;
}

int main(void)
{
//    len = z() / 0x2710u;
    len = 800;
    setvbuf(stdout, 0, 2, 0);
    printf("Echo string (less than %d bytes)\n", len);
    while (!service());
    puts("Bye!!");

    return 0;
}

