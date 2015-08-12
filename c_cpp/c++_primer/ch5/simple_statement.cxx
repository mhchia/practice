#include <iostream>

int main(void)
{
    ;
    ;
    ;
    ;
    ; // null statement

    unsigned int i = 0;
    while (i <= 10); // infinite loop because of null statement
        ++i;

    while (i <= 10) { // while only accept one statement. If we need more than one, then we should use block (enclosed by curly braces.).
        std::cout << i << " ";
        ++i;
    }
    std::cout << std::endl;
}

