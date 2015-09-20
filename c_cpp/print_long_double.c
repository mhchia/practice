#include <stdio.h>
#include <string.h>

int main(void)
{
    long double a1 = 797928016.99999163l;
    char buf[1000] = {0};
    sprintf(buf, "%Lf", a1);
    printf("%s\n", buf);
}

