#include <iostream>

int main()
{
    std::cout << "I will sum up integers you enter" << std::endl;
    int val = 0, sum = 0;
    while (std::cin >> val) {
        sum += val;
    }
    std::cout << "sum is " << sum << std::endl;
    return 0;
}
