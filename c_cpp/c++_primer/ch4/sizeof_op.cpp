#include <iostream>

class Test
{
public:
    unsigned int a;
};

int main(void)
{
    Test data, *p;
    // sizeof operator returns constexpr size_t
    // sizeof(type), sizeof expr
    std::cout << sizeof(Test) << std::endl; // 4
    std::cout << sizeof data << std::endl; // 4
    std::cout << sizeof p << std::endl; // 8, because that 64bits pointer
    std::cout << sizeof *p << std::endl; // 4, although p has undefined value, because that sizeof doesnt evaluate its operand, here is ok. Otherwise, dereferencing an undefined pointer is undefined.
    std::cout << sizeof data.a << std::endl; // 4
    std::cout << sizeof Test::a << std::endl; // 4

    int ia[10] = {}; // list init.
    constexpr size_t sz = sizeof(ia) / sizeof(int);
    int ba[sz] = {}; // list init a same size array.
    std::cout << std::end(ba) - std::begin(ba) << std::endl; // pointers difference on the same object yields the ptrdiff_t, this is the size of an array.
}

