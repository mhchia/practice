#include <stdio.h>

#define HAHA(X) void X(a) { printf(#X); }

HAHA(NO)

int main(void)
{
    NO();
}

