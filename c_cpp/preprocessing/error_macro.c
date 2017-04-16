#include <stdio.h>

#ifndef HELLO
    #error "You Must Define HELLO !"
#endif

char *a = HELLO;
int main(void)
{
    printf("%s\n", a);
}

