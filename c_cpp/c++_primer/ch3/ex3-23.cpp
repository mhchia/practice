#include <vector>
#include <iostream>

using std::vector;
int main(void)
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
        *it *= 2;
    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
        std::cout << *it << std::endl;

    return 0;
}

