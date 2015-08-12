#include <iostream>

using std::cout;
using std::endl;

int f() { cout << "f"; return 0;}
int g() { cout << "g"; return 0;}
int h() { cout << "h"; return 0;}
int j() { cout << "j"; return 0;}

int main(void)
{
    int i = 0;
    cout << i << " " << ++i << endl; // undefined behavior. because in most cases the evalution order of an expression is undefined. i.e. we dont know "i" will be evaluated first or "++i" will be evaluated first.
    // in our case, compiler first evaluate "++i" then evaluate "i", thus print 1 1
    cout << (f() + g() * h() + j()) << endl;

    cout << i << endl;
    return 0;
}

