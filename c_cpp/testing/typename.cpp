#include <iostream>

/*
    This .cpp is to test for the usage of the keyword 'typename'
*/

// first usage, typename == class in 泛型編程 (generic programming)
template <typename T>
const T& max(const T& x1, const T& x2)
{
    return x1 > x2 ? x1 : x2;
}
template <class T>
const T& min(const T& x1, const T& x2)
{
    return x1 < x2 ? x1 : x2;
}

// the second usage is to explicitly tell the compiler that a symbol is a type rather than a variable name.

namespace ha{
    typedef int Myint;
};

int shit;
template <typename T>
void test(const T&)
{

//    T::Myint *shit; // compiler will not know if the * sign is (a multiplication for T::Myint and shit) or (a type-modifier pointer). However, this line will be compiled successfully.
    typename T::Myint *shit; // typename explicitly tell compiler that T::Myint is a type.
}


int main(void)
{
    const int x1 = 1, x2 = 2;

    std::cout << min(x1, x2) << std::endl;
    std::cout << max(x1, x2) << std::endl;

    return 0;
}

