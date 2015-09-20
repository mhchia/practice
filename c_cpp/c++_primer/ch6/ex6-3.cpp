#include <iostream>
#include "Chapter6.h"

int fact(int n)
{
    int sum = 1;
    while (n >= 1)
        sum *= n--;

    return sum;
}

int main(void)
{
    std::cout << fact(5) << std::endl;
}

