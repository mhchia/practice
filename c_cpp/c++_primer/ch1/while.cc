#include <iostream>

int main(void)
{
    int sum = 0, val = 1;

    while (val <= 10) {
        sum += val;
        ++val;
    }
    // A block is zero or more statements enclosed by curly braces.
    // So zero statement is ok!
    while (0) {
    }
    (std::clog << "sum from 1 to 10 is ") << sum << std::endl;
}
