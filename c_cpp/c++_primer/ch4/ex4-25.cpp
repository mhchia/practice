#include <iostream>

int main(void)
{
    char cq = ~'q' << 6; // i think is -2^7
    long int iq = (~'q' << 6); // i think is 2^7 + 2^8 + 2^9 + 2^13
    std::cout << static_cast<int>(cq) << std::endl;
    std::cout << iq << std::endl;

}

