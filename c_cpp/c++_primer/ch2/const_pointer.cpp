#include <iostream>

int main(void)
{
    int errNumb = 0;
    // assign errNumb's addr to a const pointer curErr
    int *const curErr = &errNumb;
    // we can modify the object using a const pointer
    *curErr = 1;
    // however, we cannot modify the value held by the const pointer!
    /*
    curErr = 0;
    */

    const int a = 0;
    // a const pointer to const int
    const int *const cpci = &a;

    return 0;
}

