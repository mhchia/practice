#include <iostream>

void SwapPointer(int *&a, int *&b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void SwapPointer(int **pa, int **pb) // pa store the address of pointer a
{
    int *temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main(void)
{
    int *a = (int *)0x10, *b = (int *)0x20;
    SwapPointer(a, b);
    std::cout << a << " " << b << std::endl;
    SwapPointer(&a, &b);
    std::cout << a << " " << b << std::endl;
}
