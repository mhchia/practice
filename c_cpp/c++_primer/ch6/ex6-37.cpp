#include <iostream>

using std::string;

string c[10]; // default init to "".

/* 1. withou alias */
string (&return_c(void))[10]
{
    return c;
}

/* 2. using typedef and alias (c++11) */
typedef string arrS[10];
using arrS = string[10];
arrS &func1(void)
{
    return c;
}

/* 3. using trailing return type */
auto func2(void) -> string (&)[10]
{
    return c;
}

/* 4. using decltype */
decltype(c) &func3(void)
{
    return c;
}

int main(void)
{

}

