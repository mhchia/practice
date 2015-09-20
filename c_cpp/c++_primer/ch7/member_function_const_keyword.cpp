#include <iostream>

class A
{
public:
    int b;
    void DoNothing() {}
    void DoNothingConst() const { std::cout << b << std::endl; }
    /* above is equivalent to ..
    void DoNothingConst(const A *const this) { std::cout << this->b << std::endl; }
    */
};

int main(void)
{
    /*
        If a object is const type, it must call the const version of member function.
        When we call a member function, the compiler pass the invoking object's address
        to the member function as the initializer for the implicit parameter `this`.
        Because that `this` is const pointer to nonconst by default, we cannot use
        a ptr to const to initialize a ptr to nonconst.
        The `const` keywork solved this problem. It modify the `this` parameter's type in a
        member function, from const-ptr-to-nonconst to const-ptr-to-const.
        As a result, the member function can be called by both const and nonconst objects. (because the nonconst can be converted to const)
     */
    const A a;
//    a.DoNothing(); // error: passing ‘const A’ as ‘this’ argument of ‘void A::DoNothing()’ discards qualifiers
    a.DoNothingConst();

    A b;
    b.DoNothing(); // ok
    b.DoNothingConst(); // ok
}
