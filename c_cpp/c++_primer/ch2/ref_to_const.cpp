#include <iostream>

int main(void)
{
    double dval = 3.14;
    // ref to nonconst must be bound to a exactly same type object.
    /* this will incur init error
    int &ri = &dval;
    */
    // but this work.
    double &rd = dval;
    std::cout << "Address for dval : " << &dval << " Address for ref-to-dval : " << &rd << std::endl;

    const double &rd1 = dval;
    std::cout << "Address for dval : " << &dval << " Address for ref-to-const-dval : " << &rd1 << std::endl;

    const double &rd2 = dval * 2;
    std::cout << "Address for dval : " << &dval << " Address for ref-to-const-expression : " << &rd2 << std::endl;

    const int &rci = dval;
    std::cout << "Address for dval : " << &dval << " Address for ref-to-const-int to dval : " << &rci << std::endl;
    return 0;
}

