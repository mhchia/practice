#include <iostream>

int Max(const int a, const int *b)
{
    return (a > *b) ? a : *b;
}

int main(void)
{
    int a = 1, b = 2;
    std::cout << Max(a, &b) << std::endl;

    return 0;
}

