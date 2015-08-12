#include <iostream>

int main(void)
{
    int a = 3.14 + 3; // 3 is converted to 3.14 due to operator +, so we get 6.14. Then, 6.14 is converted to 6 due to the initialization.
    std::cout << a << std::endl;

    float b = 10000000000000000; // 1e+16
    float c = 1000.0000001; // 1000
    std::cout << b << std::endl;

    decltype(100LL+1000.0f) d;
    std::cout << sizeof(100LL) << std::endl; // 8
    std::cout << sizeof(1000.0f) << std::endl; // 4
    std::cout << sizeof(d) << std::endl; // 4, integral type always converted to floating-point type.

    unsigned int e = 1;
    int f = -1;
    std::cout << e << std::endl;
    std::cout << e + f << std::endl; // -1 turned to 2^32-1, and then (2^32-1) + 1 = 2^32, which wrapped around and result is 0.

    bool    flag;   char            cval;
    short   sval;   unsigned short  usval;
    int     ival;   unsigned int    uival;
    long    lval;   unsigned long   ulval;
    float   fval;   double          dval;

    unsigned int ui = 2;
    fval = 2.5;
    dval = ui * fval;
    std::cout << dval << std::endl; // 5




    return 0;
}

