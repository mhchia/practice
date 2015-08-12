
#include <iostream>
char f()
{
}

int main(void)
{
    int x;
    decltype(f()) sum = x; // declare sum as the type of the object return from f()
    std::cout << sizeof(sum) << std::endl; // will be 1 because that f() returns a char
    sum = 1;
    const int ci = 0, &cj = ci;
    decltype(ci) a = 0; // a has const int
    decltype(cj) b = a; // b is ref-to-const-int
//    decltype(cj) c; // error! c is ref-to-const-int, must be initialized.
    decltype(1 + 2) d;
    std::cout << d << std::endl;

    /* Generally speaking, objects on the left hand side of an assignment will be considered as reference type.*/

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) y; // ok, though r is int&, the expression is int, so y is int
//    decltype(*p) z; // error, z is ref-to-int
//    decltype ((i)) l; // error, parentheses make i be deduced as int&. parenthesized variables are always deduced as ref type. () makes compiler think that this is an expression, and 'i' is on the left-hand side of an assignment, thus (i) will be consider as 'reference'

    int test;
    std::cout << (test < (5 + 2)) << std::endl;
}

