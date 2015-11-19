#include <iostream>

class A
{
public:
    int a;
    A(int a) { this->a = a; }
//    A() { a = 0; } // we need to define a default constructor ourselves if the compiler doesn't do this for us(when we defined one constructor, compiler will not define a default constructor for us.)
};

class B {};

class C
{
    A a; // A has no default constructor. Thus compiler dont know how to default initializer a. Then, C has no default constructor, too.
};

int main(void)
{
    /* case 1 */
//    A a; // error, because that the compiler provide us with a default constructor ONLY IF we dont define ANY constructor!. In this case, we defined A(int a), a constructor. Thus, we need to define a default constructor ourselves.

    B b; // b defines no constructor, so compiler defines a synthesized default constructor for us.

    /* case 2 */
    // if we have built-in or compound type class member, we should either have in-class initializers or define a default constructor ourselves to ensure those type class member are not default init and have garbage value.

    /* case 3 */
//    C c; // because C has no default constructor, we cannot default init C.
}

