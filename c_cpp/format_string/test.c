#include <stdio.h>

int main(void)
{
    char a[10] = {0};
    a[0] = 'h';
    a[1] = 'a';
    printf("%$1s\n", a);
}

