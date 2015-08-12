#include <iostream>

int main(void)
{
    // diff
    const int a = 2;
    auto auto_a = a; // int
    auto_a = 1; // ok
    decltype(a) decl_a = a; // const int
//    decl_a = 1; // error.

    // same
    int b;
    auto auto_b = b; // int
    auto_b = 1; // ok
    decltype(b) decl_b = b; // int
    decl_b = 1; // ok
}

