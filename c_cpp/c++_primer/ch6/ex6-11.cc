#include <iostream>

void reset(int &i)
{
    i = 0;
}

int main(void)
{
    int i = 10;
    std::cout << i << std::endl;
    reset(i);
    std::cout << i << std::endl;

    return 0;
}
