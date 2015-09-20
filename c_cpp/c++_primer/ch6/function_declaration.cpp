#include <iostream>

int aaaaaaaaaa(int, int, int); // it is ok to declare function which is undefined only if we never use them.

int bb(int, int); // declaration can omit parameters names. we should only ensure that the types and numbers of parameters are correct.

int main(void)
{

    std::cout << bb(1, 2) << std::endl;
}

int bb(int a, int b)
{
    return a + b;
}
