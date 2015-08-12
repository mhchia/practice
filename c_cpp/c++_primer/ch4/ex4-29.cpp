#include <iostream>

int main(void)
{
    int x[10]; int *p = x;
    std::cout << "sizeof(x) / sizeof (*x) : " << sizeof(x) / sizeof(*x) << std::endl;
    std::cout << "sizeof x : " << sizeof(x) << std::endl;
    std::cout << "sizeof *x : " << sizeof(*x) << std::endl;
    std::cout << "sizeof(p) / sizeof (*p) : " << sizeof(p) / sizeof(*p) << std::endl;
    std::cout << "sizeof(p) : " << sizeof(p) << std::endl;
    std::cout << "sizeof(*p) : " << sizeof(*p) << std::endl;

    return 0;
}

