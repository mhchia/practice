#include <iostream>

#include "Person.h"

int main(void)
{
    // default init.
    Person A;
    Person B("Kevin", "road");
    print(std::cout, A) << std::endl;
    print(std::cout, B) << std::endl;
}

