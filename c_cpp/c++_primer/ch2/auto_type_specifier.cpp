#include <iostream>

int main(void)
{
    int i = 0, &r = i;
    auto a = r; // ok, r is int
//    auto i1 = 1, i2 = 1.0; // error: inconsistent deduction for ‘auto’, 合理，因為compiler應會將其當成同個declaration同type
    const int ci = i, &cr = ci;
    auto b = ci; // b is int type rather than const int.
    b = 1; // ok
    auto c = cr; // int
    auto d = &i; // d is "ptr to int"
    auto e = &ci; // e is "const int *", why? because ci is const int, so the pointer point to it must be a "const int *"
    const auto f = ci; // f is const int type. "const auto" explicitly tells compiler that f is a const qualified type.

    auto &g = ci; // tell compiler that g is a ref
//    auto &h = 42; // error, can only bind to an object rather than a literal
    const auto &j = 42; // ok, we can bind a const ref to a literal. ref-to-const很猛，可指到literal, non-const, expression. 因為compiler會幫忙作隱式轉換。
    a = 42; // ok
    b = 42; // ok
    c = 42;
//    d = 42; // cannot point a ptr to a literal
//    e = 42; // 1. cannot point a ptr to a literal
    g = 42; // g is a ref-to-const-int, const int cannot be modified
}

