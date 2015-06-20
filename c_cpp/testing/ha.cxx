#include <iostream>

auto ptr = [](void) { std::cout << "ha" << std::endl;};

int main(void)
{
    auto a = 1.2;
    std::cout << sizeof(a) << std::endl;
    auto ptr = [](void) { std::cout << "hello world" << std::endl;};
    ptr();
    return 0;
}

