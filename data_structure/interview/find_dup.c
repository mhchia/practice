#include <stdio.h>
#include <stdlib.h>

int FindDup(int a[], int n)
{
    int *count = (int*)malloc(n * sizeof(int));
    int min = a[0], i;
    for (i = 0; i < n+1; ++i)
        if (a[i] < min)
            min = a[i];
    for (i = 0; i < n+1; ++i)
        ++count[a[i] - min];
    for (i = 0; i < n+1; ++i)
        if (count[i] > 1)
            return i+min;
    return -1; // indicate not found.
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 6, 7};
    printf("%d\n", FindDup(a, 7));
}

