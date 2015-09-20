#include <iostream>

typedef bool Func(const std::string&, int); // Func is a function type.
typedef int F(int*, char*); // F is a Function type
using F = int(int*, char*); // F is a Function type
using PF = int(*)(int*, char*); // F is a pointer to function type.


PF f1(int); // ok, f1 returns function pointer
//F f1(int); // error, : ‘f1’ declared as function returning a function
F *f1(int); // ok, f1 returns function pointer

auto f1(int) -> int (*)(int*, char*);

decltype(f1) *GetFunc(void);

int main(void)
{

}

