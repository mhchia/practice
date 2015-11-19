#include <iostream>

int main(void)
{
    size_t sz;
    constexpr size_t cesz = 10;

    for (int i = 0; i < 100000; ++i) {
        std::cout << i << std::endl;
    }

    return 0;
}
