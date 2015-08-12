#include <iostream>

int main(void)
{
    int i = 0;
    /*
    if (42 = i) // error, lvalue required as the left operand of assignment.
        std::cout << "!!" << std::endl;
    */
    if (i = 42)
        std::cout << "!!!" << std::endl;
}

