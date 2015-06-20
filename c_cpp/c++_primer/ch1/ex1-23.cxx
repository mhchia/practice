#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item, sum;
    int count = 1;
    if (std::cin >> sum) {
        count = 1;
        while (std::cin >> item) {
            if (item.isbn() == sum.isbn()) {
                count += 1;
                sum += item;
            } else {
                std::cout << sum << " : " << count << std::endl;
                count = 1;
                sum = item;
            }
        }
        std::cout << sum << " : " << count << std::endl;
    }
}
