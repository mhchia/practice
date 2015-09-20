#include <iostream>

unsigned int Test()
{
    static unsigned int a = -1;
    ++a;

    return a;
}

int main(void)
{
    std::cout << Test() << std::endl;
    std::cout << Test() << std::endl;
    std::cout << Test() << std::endl;
    std::cout << Test() << std::endl;

}
