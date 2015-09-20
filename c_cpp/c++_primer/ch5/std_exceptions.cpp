#include <iostream>
#include <stdexcept>
#include <exception>

int main(void)
{
    /* must without initializer */
    throw std::exception();
    throw std::bad_alloc();

    /* must with initializer such as empty string. */
    throw std::runtime_error("");
    throw std::range_error("a");
}

