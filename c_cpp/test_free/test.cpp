#include <iostream>
#include <cstdlib>

int main(void)
{
    int *ptr = static_cast<int *>(std::malloc(sizeof(int)));
    std::free(ptr);
    ptr = nullptr;
    std::free(ptr);
}

