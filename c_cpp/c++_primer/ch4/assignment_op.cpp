#include <iostream>
#include <vector>

int main(void)
{
    int i = 0, j = 0, k = 0; // init, not assignments
    const int ci = i; // initializations, not assignments

    /*
    1024 = k; // error, literal are rvalues
    i + j = k; // error, arithematic expr are rvalues
    ci = k; // error, ci is a const lvalue.
    */

    k = 0; // ok
    k = 3.14; // ok, if the operands of assignment operators are different types, the right-hand operand will be converted to the type of the left. so, k = 3;

    k = {3.14}; // error, narrowing conversion.
    std::vector<int> vi;
    vi = {0, 1}; // ok, braced initializer list in c++11
    std::cout << vi.size() << std::endl; // 2
    vi = {}; // the elements in vi is replaced by {}
    std::cout << vi.size() << std::endl; // 0

    int ival, jval;
    ival = jval = 0; // ok, (jval = 0) returns the lvalue jval and assigned to ival
    int *pval;
//    ival = pval = 0; // error, expr (pval = 0) returns the lvalue int*. int* and int cannot be the operand of '=' in the same time.
}

