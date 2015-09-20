#include <iostream>

using std::cout;
using std::endl;

void f(void) { cout << "(void) "; }
void f(int a) { cout << "(int) "; }
void f(int a, int b) { cout << "(int, int) "; }
void f(double a, double b = 3.14) { cout << "(double, double) "; }

int main(void)
{
    // a.
//    cout << "a"; f(2.56, 42); cout << endl; // error, call of overloaded f(double, int) is ambiguous.
    // b.
    cout << "b"; f(42); cout << endl;
    // c.
    cout << "c"; f(42, 0); cout << endl;
    // d.
    cout << "d"; f(2.56,  3.14); cout << endl;
}

