#include <stdio.h>


int BinarySearch(int a[], int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (k == a[m])
            return m;
        else if (k > a[m])
            l = m + 1;
        else
            r = m - 1;
    }
    return -1; // not found.
}

int BinarySearchRecur(int a[], int n, int k, int l, int r)
{
    if (l <= r) {
        int m = (l + r) / 2;
        if (k == a[m])
            return m;
        else if (k > a[m])
            l = m + 1;
        else
            r = m - 1;
        return BinarySearchRecur(a, n, k, l, r);
    }
    return -1;
}

int main(void)
{
    int a[] = {1, 3, 8, 9, 20, 56, 88, 100};
    printf("%d\n", BinarySearchRecur(a, 8, 9, 0, 7));

    return 0;
}

