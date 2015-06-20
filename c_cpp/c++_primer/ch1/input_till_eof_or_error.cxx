#include <iostream>

int main()
{
    int a = 0, sum = 0;
    while (std::cin >> a) {
        sum += a;
    }
    std::cout << "sum : " << sum << std::endl;
    return 0;
}
