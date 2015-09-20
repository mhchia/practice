#include <iostream>
#include "ex6-10.h"

void swap(int * const a, int * const b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 1, b = 2;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "After  swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}

