#include <iostream>

class A {
public:
    int a, b, c;
/*
    A();
    ~A();
*/
};

/*
A::A()
{
    std::cout << "construct" << std::endl;
}

A::~A()
{
    std::cout << "destruct" << std::endl;
}
*/

int main(void)
{
    A a = {1, 2, 3};
    std::cout << "in main" << std::endl;
    std::cout << "after a" << std::endl;
}

