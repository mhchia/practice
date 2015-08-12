#include <iostream>
#include <vector>

using std::vector;

bool IsPrefix(vector<int> ivec1, vector<int> ivec2)
{
    if (ivec1.size() > ivec2.size())
        return false;

    for (vector<int>::size_type i = 0; i < ivec1.size(); ++i) {
        if (ivec1[i] != ivec2[i]) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    vector<int> a1{0, 1, 1, 2}, a2{0, 1, 1, 2, 3, 4}, a3{0, 1, 2};

    std::cout << IsPrefix(a1, a2) << std::endl;
    std::cout << IsPrefix(a3, a2) << std::endl;

    return 0;
}

