#include <iostream>

int main(void)
{
    int t = 1;
    int a;
    a = 0x1123 >> (t - 4); // result will be 0, because that >> operator takes unsigned arguments?, -3 will be turned to -3 + 2147483648
    a = 0x1123 >> (-3); // result will be 35096, cause the compiler turned it to << 3 ?

    std::cout << a << std::endl;
    return 0;
}

