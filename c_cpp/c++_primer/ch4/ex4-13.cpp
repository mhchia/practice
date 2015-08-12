#include <iostream>

int main(void)
{
    int i;
    double d;
    d = i = 3.5;
    std::cout << i << " " << d << std::endl; // 3 3.0
    i = d = 3.5;
    std::cout << i << " " << d << std::endl; // 3 3.5
}

