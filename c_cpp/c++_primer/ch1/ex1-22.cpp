#include <iostream>
// non standard library use "
#include "Sales_item.h"

int main()
{
    Sales_item i, sum;
    while (std::cin >> i) {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}
