#include <iostream>

int main(void)
{

    std::cout << "Enter 2 numbers:" << std::endl;
    int v1, v2;
    (std::cin >> v1) >> v2;
    (std::cout << v1);
    std::cout << " * ";
    std::cout << v2;
    std::cout << " = ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}
