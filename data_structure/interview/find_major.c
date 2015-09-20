#include <stdio.h>


int FindMajor(int a[], int n)
{
    int major = -1, count = 0;
    int i;
    for (i = 0; i < n; ++i) {
        if (count == 0)
            major = a[i];
        if (major == a[i])
            ++count;
        else
            --count;
    }

    count = 0;
    for (i = 0; i < n; ++i)
        if (a[i] == major)
            ++count;

    if (count > n / 2)
        return count;
    return -1;
}

int main(void)
{
    int a[] = {1, 2, 1, 2, 1};
    printf("%d\n", FindMajor(a, 5));

    return 0;
}

