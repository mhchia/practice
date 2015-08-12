#include <iostream>
#include <vector>

using std::vector;
int main(void)
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
        (*it) = (*it % 2) ? (*it * 2) : (*it);
    for (const auto &i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

