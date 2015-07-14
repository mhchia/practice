#include <iostream>

typedef int MyInt;
using MyChar = char; // using only in c++11

using MyFunc = int(int, int);

/*
MyFunc
{
    return 0;
}
*/
template <typename T>
void print(T a)
{
    a();
}

using Ha = char;

int main(void)
{
    std::cout << sizeof(MyChar) << " " << sizeof(MyInt) << std::endl;
    return 0;
}

