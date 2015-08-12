#include <iostream>

int main(void)
{
    int i = 1024;
    int k = -1;
    bool b = true;
    bool b2 = -b; // true, true->1->-1->true

    int ival = 42;
    double dval = 3.14;
    ival % 12; // ok
    ival % dval; // error, operand must be integers.
}

