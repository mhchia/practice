#include <iostream>

class A {
public:
    A() : a(0) { }
    void some_function() { --a; } // error: decrement of read-only member ‘A::a’
private:
    const int a;
};

int main(void)
{

}

