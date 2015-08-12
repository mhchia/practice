#include <iostream>

int main(void)
{
    int a;

    int &b = (a = 5); // operator= require its lefthand operand as lvalue, and returns an lvalue
    b = 3;
    std::cout << a << std::endl; // because that b ref to a, a is 3.

    return 0;
}

