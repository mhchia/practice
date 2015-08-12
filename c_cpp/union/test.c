#include <stdio.h>

union Data {
    int a;
    double b;
    long long int c;
};

int main(void)
{
    union Data a;
    a.c = 11ll;
    printf("%d %d %d\n", a.a, a.b, a.c);
    printf("%d %d %d\n", sizeof(a.a), sizeof(a.b), sizeof(a.c));

    return 0;
}

