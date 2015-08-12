#include <iostream>

int main(void)
{
    int a = 0;
    int &b = ++a; // ++a returns lvalue, so b and a are the same object. however, a++ not.
    std::cout << a << " " << b << std::endl; // 1 1

    b += 1;
    std::cout << a << " " << b << std::endl; // 2 2
}

