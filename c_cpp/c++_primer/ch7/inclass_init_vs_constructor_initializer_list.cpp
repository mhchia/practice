#include <iostream>

int func1()
{
    std::cout << __func__ << std::endl;
    return 1;
}

int func2()
{
    std::cout << __func__ << std::endl;
    return 2;
}

class A
{
public:
    int a = func1();
    // default constructor
    /* test in-class initializer and constructor initializer list. */
    A() { } // print "func1" only
//    A() : a(func2()) { } // print "func2" only
};

int main(void)
{
    A a;
}

