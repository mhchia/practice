#include <iostream>
#include <typeinfo>

int main()
{

    /* characters */
    std::cout << typeid(u'h').name() << std::endl; // unicode 16 character: char16_t
    std::cout << typeid(U'h').name() << std::endl; // unicode 32 character: char32_t
    std::cout << typeid(L'a').name() << std::endl; // wide char: wchar_t
    std::cout << typeid(u8"hi").name() << std::endl; // utf-8: char
    /* integer literals */
    std::cout << typeid(42).name() << std::endl; // int
    std::cout << typeid(42U).name() << std::endl; // unsigned int
    std::cout << typeid(42L).name() << std::endl; // long
    std::cout << typeid(42ULL).name() << std::endl; // Unsigned long long
    /* floating point literals */
    std::cout << typeid(2.5).name() << std::endl; // seeing '.' or scientific notation : floating point!, default float
    std::cout << typeid(1E-3F).name() << std::endl; // floating point: float
    std::cout << typeid(1E-3L).name() << std::endl; // floating point: long double

    char *shit = nullptr;
    return 0;
}
