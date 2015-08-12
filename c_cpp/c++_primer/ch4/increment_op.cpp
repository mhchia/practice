#include <iostream>

int main(void)
{
    int i = 0, j;
    j = ++i; // ++i add 1 to i and returns i as lvalue.
    j = i++; // i++ copy the unchanged value and add 1 to i, then returns the unchanged value as rvalue.

    std::cout << j << " " << j++ << std::endl; // undefined behavior. 2 1, so strange!
    return 0;

}

