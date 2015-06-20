#include <iostream>

int main()
{
    int sum = 0;
    for (int val = 1; val <= 10; ++val)
        sum += val;
    // endl will end the line and flush the stream buffer
    std::cout << "sum from 1 to 10 = " << sum << std::endl;
    return 0;
}
