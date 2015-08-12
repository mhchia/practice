#include <iostream>

int main(void)
{
    int a = -30 * 3 + 21 / 5;
    int b = -30 + 3 * 21 / 5;
    int c = 30 / 3 * 21 % 5;
    int d = -30 / 3 * 21 % 4;
    std::cout << a << " " << b << " " << c << " " << d << std::endl;
}

