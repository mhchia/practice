#include <iostream>


class A {
public:
    void say_hello();
    void say_hello() const;
};

void A::say_hello()
{
    std::cout << "hello, not const" << std::endl;
}

void A::say_hello() const
{
    std::cout << "hello, is const" << std::endl;
}

int main(void)
{
    A not_const_a;
    not_const_a.say_hello();

    const A const_a;
    const_a.say_hello();
    return 0;
}

