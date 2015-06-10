#include <iostream>

int main(void)
{
    std::cout << "/*";
    std::cout << "*/";
    // fuck, this works!! the /* and */ is prior to anything!
    std::cout << /* // "*/" /* "/*" */;
    std::cout << /* "*/" */;
}
