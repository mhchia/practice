#include <iostream>

class Base
{
public:
    virtual void print()
    {
        std::cout << "virtual" << std::endl;
    }
};

class Inh : public Base
{
public:
    void print()
    {
        std::cout << "Inh" << std::endl;
    }
};


int main(void)
{
    Inh inh;
    Base *ptr = &inh;
    ptr->print();
}

