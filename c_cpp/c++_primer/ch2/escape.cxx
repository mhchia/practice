#include <iostream>

int main()
{
    // \x0a in hex and \12 in octal are 10 in decimal
    // which is '\n' char literal
    std::cout << '\x0a' << '\12' << std::endl;
    return 0;
}
