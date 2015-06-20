#include <iostream>

int main(void)
{
    int *a = nullptr;
    int b = 1;
    // a holds the address of b
    a = &b;
    b = 2;
    std::cout << *a << std::endl;
    *a = 3;
    std::cout << b << std::endl;

    return 0;
}

