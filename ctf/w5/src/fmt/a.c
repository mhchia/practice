#include <stdio.h>

int x;

int main(void)
{
    char str[100];
    gets(str);
    x = 0;
    printf(str);
    printf("\n%08x\n", x);
}

