#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main(void)
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9}; // equivalent to vector<int> ivec = {1, 2, ..., 9};
    for (auto &i : ivec)
        i *= i;

    for (const auto &i : ivec)
        cout << i << " ";
    cout << endl;

    cout << ivec.empty() << endl;
    cout << ivec.size() << endl;
    if (5 < ivec.size()) // in case of undefined behavior
        cout << ivec[5] << endl;

    vector<int> ivec1{2};
    cout << (ivec == ivec1) << endl;
    cout << (ivec < ivec1) << endl;
}

