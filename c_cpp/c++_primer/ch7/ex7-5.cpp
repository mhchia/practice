#include <iostream>
#include "ex7-4.hpp"

int main(void)
{
    Person a;
    a.name = "ken";
    a.address = "123 rd.";
    std::cout << a.GetName() << a.GetAddress() << std::endl;

    return 0;
}

