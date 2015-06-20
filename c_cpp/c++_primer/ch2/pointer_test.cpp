#include <iostream>


int a = 0;


// void ptr can be used to pass an address to a function
// and it can also used for returning an address.
void *printing(void *ptr)
{
    return ptr;
}

int main(void)
{
    // void ptr can eat point to any type.
    int a = 1;
    void *ptr = &a;

    // type must be consistent, so error occurs.
    /*
    double b = 0.5;
    int *ptr1 = &b;
    */

    // you cannot directly assign an address to a pointer!
    // why?? because that these checks are at compile time!
    // you can only have a valid pointer! @primer p.52
    /*
    void *pppp = 0x7fff308c2274;
    */

    // it is illegal to assign an int variable to a pointer,
    // even if the variable's value happens to be 0.
    /*
    int c = 0;
    int *pp = c;
    */

    std::cout << printing(&a) << std::endl;

    return 0;
}

