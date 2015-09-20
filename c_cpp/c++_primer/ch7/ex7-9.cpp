#include <iostream>

#include "ex7-4.hpp"


std::istream &read(std::istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &item)
{
    os << item.name << " " << item.address;
    return os;
}

int main(void)
{
    Person a;
    read(std::cin, a);
    if(!print(std::cout, a)) {
        std::cerr << "Error!" << std::endl;
    }

}

