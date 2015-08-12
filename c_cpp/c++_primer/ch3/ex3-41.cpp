#include <iostream>
#include <vector>
int main(void)
{
    int a[] = {1, 2, 3};
    std::vector<int> ivec(a, a+3); // a.begin() and a.end() (a.end() is the one past the last element.)
    constexpr size_t a_size = 10;
    int a1[a_size] = {}; // list init to 0's

    for (size_t i = 0; i < ivec.size(); ++i)
        a1[i] = ivec[i];

    for (size_t i = 0; i < a_size; ++i)
        std::cout << a1[i] << " ";
    std::cout << std::endl;
}

