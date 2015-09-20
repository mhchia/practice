#include <iostream>
#include "Chapter6.h"

int abs(int n) { return (n > 0) ? n : -n; }

int main(void)
{
    int n;
    std::cin >> n;

    std::cout << abs(n) << std::endl;

    return 0;
}

