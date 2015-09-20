#include <iostream>
#include <iomanip>

int main(void)
{
    std::cout << sizeof(long double) << " " << sizeof(double) << std::endl;
    long double a = 797928016.99999163;
    std::cout << std::fixed << std::setprecision(8);
    std::cout << a << std::endl;
}

