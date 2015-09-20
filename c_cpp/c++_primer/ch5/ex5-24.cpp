#include <iostream>
#include <stdexcept>

int main(void)
{
    int a, b;

    std::cin >> a >> b;

    if (b == 0) {
        throw std::runtime_error("the divider cannot be zero.");
    }

    std::cout << (a / b) << std::endl;

}

