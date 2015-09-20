#include <stdio.h>
#include <math.h>
#include <string.h>

int atoi_mine(char a[])
{
    int sum = 0;

    int i;
    for (i = strlen(a) - 1; i >= 0; --i) {
        sum += (a[i] - '0') * pow(10, strlen(a) - i - 1);
    }
    return sum;
}

int main(void)
{
    char a[] = "0";
    char b[] = "1";

    printf("%d\n", atoi_mine(a) + atoi_mine(b));
}

