#include <iostream>
#include <cassert>


int main(void)
{
#ifndef NDEBUG
    std::cerr << "haha" << std::endl;
#endif

    // if NDEBUG is defined, assert will be of no use.
    assert(true == false); // defined in cassert, assert.cpp:6: int main(): Assertion `true == false' failed.

    return 0;
}

