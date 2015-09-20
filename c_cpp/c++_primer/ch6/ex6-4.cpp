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
    int n;
    std::cout << "Enter a number, I will evaluate its factorial for you : ";
    std::cin >> n;
    std::cout << std::endl << fact(n) << std::endl;

    return 0;
}

