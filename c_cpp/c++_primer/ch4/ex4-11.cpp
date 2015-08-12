#include <iostream>

int main(void)
{
    int a = 4, b = 3, c = 2, d = 1;
    if (a > b && b > c && c > d)
        std::cout << "a > b > c > d" << std::endl;

    return 0;
}

