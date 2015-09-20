#include <iostream>

using std::initializer_list;

int sum_ili(initializer_list<int> ili)
{
    int sum = 0;

    for (const auto i : ili) {
        sum += i;
    }

    return sum;
}

int main(void)
{
    std::cout << sum_ili({1, 2, 3, 5}) << std::endl;
}

