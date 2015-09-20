#include <iostream>

using std::string;

bool FuncA(const string &a, const string &b)
{

}
bool FuncA(const string &a, int b)
{
}

int FuncB(const string &a, const string &b);

/* function pointer type is defined by return type and params type. */
bool (*pf)(const string &, const string &) = nullptr;

/* function pointer as parameters */
void haha(const string &,
          bool pf(const string &, const string &)
);

/* function alias */
typedef bool Func(const string &, const string &); // function type
typedef decltype(FuncB) Func2; // function type

typedef bool(*FuncP)(const string &, const string &); // function pointer type
typedef decltype(pf) *FuncP1; // pointer
typedef decltype(haha) *FuncP2; // pointer

void useBigger(const string &, const string &, FuncP2);

int main(void)
{
    pf = FuncA; // ok, point to FuncA
    pf = &FuncA; // ok, equivalent to above
//    pf = FuncB; // error, different function pointer type.
    pf = 0;

    pf = FuncA; // pf points to FuncA(const string&, const string &) rather than FuncA(const string &, int)
}

