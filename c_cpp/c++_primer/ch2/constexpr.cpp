#include <iostream>


constexpr int size(void)
{
    return 1;
}

int global_weak;
int global_strong = 1;

/*
 * adding constexpr before a declaration type can ask compiler to verify that a variable is a const expression.
 */
int main(void)
{
    constexpr int mf = 1.0; // implicit converision
    constexpr int limit = mf + 1; // ok, cuz that mf is a constexpr
    constexpr int sz = size(); // ok only if size is a constexpr function.

    static int static_var = 1;
    int a = 2;
//    constexpr int *p1 = &a; // fail: constexpr pointer can only point to fixed address var.
    constexpr int *p2 = &static_var; // ok, static is fixed address.
    constexpr int *p3 = &global_weak; // ok
    constexpr int *p4 = &global_strong; // ok
    /* constexpr pointer is like const pointer rather than like pointer to const*/
    
}

