#include <iostream>

int main(void)
{
    int i = 42;
    int *p = nullptr;
    // define a reference to pointer, refer to pointer p
    int *&r = p; // now, the operation on r is identical to operation on p
    r = &i; // so it means that r(=p) holds the addr of i, i.e. points to i
    std::cout << *p << std::endl;
    return 0;
}
