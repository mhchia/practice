#include <iostream>

void swap(int &a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 1, b = 2;
    std::cout << a << " " << b << std::endl;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    return 0;
}
