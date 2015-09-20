#include <iostream>

int func1(int) {}

int func2(int, int) {}
int func2(double, double) {}

int main(void)
{

    /*
        Candidate function
        1. same name.
        2. is visible when be called.
    */
    int func1();
    func1(); // func1(int) is not visible, so func1(int) is not a candidate funcation.

    /*
        Viable function
        1. params number are the same as the argument numbers.
        2. type are match or can be converted.
    */

    func2(1, 0.5); // error, call of func2(int, double) is ambiguous.
    /*
        An Overall best match is
        1. all arguments are not worse than any other viable function.
        2. at least one argument better than any other viable function.
    */
}

