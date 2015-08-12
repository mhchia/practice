#include <iostream>

int main(void)
{
    int ia[3][4] = {}; // list- init, nonspecified value init to 0
    int (*p)[4] = &ia[2];


    for (int (*r)[4] = ia; r != ia + 3; ++r) { // r is a pointer to array of ints
        for (int *c = &(*r)[0]; c != &(*r)[4]; ++c) { // c is a pointer to int, and *r is the array instance, because that the array name can be taken as the address of an array, we can write int *c = *r. But to understand the concept, we make c points to the arrays first element, which is (*r)[0]. And while the c points to the one past the last element (*r)[4], we jump out the for loop
            std::cout << *c << " ";
        }
    }
    std::cout << std::endl;

    // equivalent to
    for (auto p = std::begin(ia); p != std::end(ia); ++p)
        for (auto q = std::begin(*p); q != std::end(*p); ++q) // p is the pointer to the array, so we dereference it to get the array.
            std::cout << *q << " ";
    std::cout << std::endl;

    using int_array = int[4];
    typedef int int_array[4]; // equivalent to above, but not so clear.

    for (int_array *p = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            std::cout << *q << " ";
    std::cout << std::endl;
}

