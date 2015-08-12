#include <iostream>

int main(void)
{
    const char a[] = {'c', '+', '+'}; // list init without '\0'
    const char *cp = a;
    while (*cp) {
        std::cout << *cp << std::endl;
        ++cp;
    } // printing string in a, but without '\0' incurs undefined behavior.
}

