#include <iostream>

int main(void)
{
    int ival = 2;
    int *p = &ival;
    int **pp = &p;
    // if pp not record the addr of p, logic fails and compiler error.
    /*
    int **pp = p;
    */

    std::cout << "value of ival : " << ival;
    std::cout << " indirect value : " << *p;
//    std::cout << " double indirect : " << **pp << std::endl;
    return 0;
}

