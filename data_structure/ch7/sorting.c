#include <stdio.h>

void Swap(int *a, int *b)
{
/*
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
*/
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Print(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    puts("");
}

void InsertionSort(int a[], int n)
{
/*
    [           ]
    <-
    <----
    <--------
*/
    int i, j;
    for (i = 1; i < n; ++i) {
        j = i;
        int data = a[j];
        while (data < a[j - 1] && j > 0) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = data;
    }
}

void SelectionSort(int a[], int n)
{
/*
    [           ]
    ------------>
     ----------->
        -------->
*/
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        int index = i;
        for (j = i + 1; j < n; ++j) {
            if (a[j] < a[index]) {
                index = j;
            }
        }
        if (i != index) // this line is critical, because that if we the same object to do no-temp swap, there will be error.
            Swap(&a[index], &a[i]);
    }
}

void BubbleSort(int a[], int n)
{
/*
    [           ]
    ------------>
    ---------->
    ------->
*/
    int i, j;
    for (i = 0; i < n; ++i) {
        int flag = 0;
        // for (j = 0; j < n - i - 1; ++j) {
        for (j = 0; j < n - 1; ++j) {
            if (a[j] > a[j + 1]) {
                Swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
            return;
    }
}

void qsort(int *a, int m, int n)
{
    if (m < n) {
        int i = m, j = n + 1;
        // m is pk's position.
        while (i < j) {
            do {
                ++i;
            } while (a[i] < a[m]);
            do {
                --j;
            } while (a[j] > a[m]);
            if (i < j)
                Swap(&a[i], &a[j]);
        }
        Swap(&a[m], &a[j]);
        qsort(a, m, j - 1);
        qsort(a, j + 1, n);
    }
}

void QuickSort(int *a, int n)
{
    qsort(a, 0, n - 1);
}

typedef void Func(int*, int);

int main(void)
{
    Func *SortFunctions[] = {
        InsertionSort,
        SelectionSort,
        BubbleSort,
        QuickSort
    };
    void (*Sort)(int*, int) = SortFunctions[0];
    int i;
    for (i = 0; i < 4; ++i) {
        int a[] = {0, 8, 218, 9, 5555, 40, 39, 38, 7, 19, 33};
        SortFunctions[i](a, 11);
        Print(a, 11);
    }
}
