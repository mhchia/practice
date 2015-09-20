#include <stdio.h>
#include <stdlib.h>

void transpose(int a[], int m, int n)
{
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < i; ++j) {
            int temp = a[n * i + j];
            a[n * i + j] = a[n * j + i];
            a[n * j + i] = temp;
        }
    }

}

void print_matrix(int a[], int m, int n)
{
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j)
            printf("%d ", a[n * i + j]);
        puts("");
    }
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6};
    print_matrix(a, 2, 3);
    transpose(a, 2, 3);
    print_matrix(a, 3, 2);
}

