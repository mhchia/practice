#include <iostream>

int main(void)
{
    int a = 3, b = 4;
    decltype(a) c = a;
    c = 1;
    std::cout << a << std::endl; // should be 3

    decltype(a = b) d = a; // The type is a reference to the type of the left-hand operand. So it is int&
    d = 1;
    std::cout << a << std::endl; // should be 1
}

