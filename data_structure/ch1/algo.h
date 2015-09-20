#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void perm(int i, int n, const char buf[])
{
    char str[100000];
    strcpy(str, buf);

    if (i == n - 1) {
        int j;
        for (j = 0; j < n; ++j) {
            printf("%c", str[j]);
        }
        puts("\n");
    }

    printf("i = %d, n = %d\n", i, n);
    int j;
    for (j = i; j < n; ++j) {
        swap(&str[i], &str[j]);
        perm(i + 1, n, str);
        swap(&str[i], &str[j]);
    }
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 1) {
        printf("move from %c to %c\n", a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n - 1, b, a, c);
}

unsigned int fact(const unsigned int n)
{
    if (n == 0) return 1;

    return n * fact(n - 1);
}

// n must >= 0
int fab(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fab(n - 1) + fab(n - 2);
}

int bin(int n, int m)
{
    if (m == 0 || n == m) return 1;

    return bin(n - 1, m) + bin(n - 1, m - 1);
}

int gcd(int a, int b)
{
    if (a % b == 0) return b;

    return gcd(b, a % b);
}
