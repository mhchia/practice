#include <iostream>



void hey(int c, int d)
{
    std::cout << c << " " << d << std::endl;
}

int main(void)
{
    void (*ha)(int, int);
    ha = &hey;
    (*ha)(1, 2);
}

