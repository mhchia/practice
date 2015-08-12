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

class MethodOnlyConst
{
public:
    void say_hello() const
    {
        std::cout << "hello, is const" << std::endl;
    }
};

class MethodOnlyNotConst
{
public:
    void say_hello()
    {
        std::cout << "hello, is not const" << std::endl;
    }
};

int main(void)
{
    A not_const_a;
    not_const_a.say_hello();

    const A const_a;
    const_a.say_hello();

    MethodOnlyConst not_const_b;
    not_const_b.say_hello(); // using const method

    const MethodOnlyNotConst const_b;
    const int &a = 10;
    const_cast<int&>(a);
//    const_b.say_hello(); // error, passing ‘const MethodOnlyNotConst’ as ‘this’ argument of ‘void MethodOnlyNotConst::say_hello()’ discards qualifiers
//    const_cast<MethodOnlyNotConst>(const_b);

    return 0;
}

