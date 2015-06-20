#include <iostream>

int main()
{
    std::cout << "Who goes with F\145rgus\012" << std::endl;
    std::cout << sizeof(3.14e1L) << std::endl; // 16 bytes : long double
//    std::cout << 1024.0f << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(3.14) << std::endl; // 8 bytes : double !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::cout << sizeof(3.14f) << std::endl; // 4 bytes : float
    std::cout << sizeof(3.14L) << std::endl; // 16 bytes : long double
    return 0;
}
