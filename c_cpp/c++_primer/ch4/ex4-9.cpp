#include <iostream>

int main(void)
{
    const char *cp = "Hello world";
    if (cp && *cp)
        std::cout << "cp is not null and *cp is not empty char*" << std::endl;
}

