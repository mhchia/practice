#include <iostream>

int main()
{
    int a, b;
    std::cout << "Please enter 2 numbers" << std::endl;
    (std::cin >> a) >> b;
    int max = (a < b) ? b : a;
    int min = (a < b) ? a : b;
    while (min <= max) {
        std::cout << min << std::endl;
        min++;
    }
    return 0;
}
