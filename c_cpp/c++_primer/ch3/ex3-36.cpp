#include <iostream>
#include <iterator>
#include <vector>

bool compare(int a[4], int b[4])
{
    int *abeg = std::begin(a);//, *aend = std::end(a);
    /*
    const int * bbeg = std::begin(b), *bend = std::end(b);
    while (abeg != aend && bbeg != bend) {
        ++abeg;
        ++bbeg;
    }


    if (abeg != aend || bbeg != bend)
        return false;
    */
    return true;
}

int main(void)
{
    int a[4] = {1, 2}, b[5] = {3, 4};
    std::cout << compare(a, b) << std::endl;
}
