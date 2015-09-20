#include <iostream>

// 以下三個宣告為相同
void print(const int*);
void print(const int[]);
void print(const int[10]);

int main(void)
{
    int i = 0, j[2] = {0, 1}; // list init.
    print(&i); // ok,
    print(j); // ok, j被轉成int*
    print(&j); // error, &j為int (*)[2](pointer to array of 2 ints), 不是int*
}

